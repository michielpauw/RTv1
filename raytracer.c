/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:38:46 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/15 16:16:38 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_vector	*get_origin(int id, t_list *lst)
{
	t_list		*tmp;
	t_source	*src;

	tmp = lst;
	while (tmp)
	{
		src = (t_source *)(tmp->content);
		if (src->id == id)
			return (&(src->origin));
		tmp = tmp->next;
	}
	error (1);
	return (NULL);
}

static int	get_visible_object(double *t_value, t_vector pixel, int src_id,
		t_list *objects)
{
	int			object_id;
	double		tmp;
	t_list		*tmp_list;
	t_object	*obj;
	t_vector	*dir;

	tmp_list = objects;
	object_id = 0;
	int i = 0;
	while (tmp_list)
	{
		obj = (t_object *)tmp_list->content;
		dir = ft_v_subtract(&pixel, get_origin(src_id, obj->rel_sources));
		tmp = obj->f(obj, dir);
		if (tmp > 0 && tmp < *t_value)
		{
			*t_value = tmp;
			object_id = (obj->id);
		}
		tmp_list = tmp_list->next;
		i++;
		ft_free_vector(dir);
	}
	return (object_id);
}

static int	get_pixel_value(t_scene *scene, t_vector pixel)
{
	t_list		*objects;
	double		t_value;
	int			object_id;

	objects = scene->objects;
	t_value = MAX_T_VALUE;
	object_id = -1;
	object_id = get_visible_object(&t_value, pixel, 0, objects);
	return (object_id);
}

void		raytracer(t_event *event, t_scene *scene)
{
	t_img		*img;
	t_vector	pixel;
	int			i;
	int			j;
	int			pix_val;

	img = event->img;
	i = 0;
	pixel.dim = VEC_SIZE;
	if (!(pixel.entries = (double *)malloc(sizeof(double) * VEC_SIZE)))
		error(1);
	(pixel.entries)[0] = 0.0;
	while (i < img->height)
	{
		j = 0;
		(pixel.entries)[2] = (double)(img->height / 2.0 - i);
		while (j < img->width)
		{
			(pixel.entries)[1] = (double)(j - img->width / 2.0);
			pix_val = get_pixel_value(scene, pixel);
			if (pix_val == 1)
				((int *)img->img_arr)[j + i * img->size_line_int] = 0x8f;
			else if (pix_val == 2)
				((int *)img->img_arr)[j + i * img->size_line_int] = 0xff00;
			else if (pix_val == 3)
				((int *)img->img_arr)[j + i * img->size_line_int] = 0xff0000;
			else if (pix_val == 4)
				((int *)img->img_arr)[j + i * img->size_line_int] = 0xffff00;
			else if (pix_val == 5)
				((int *)img->img_arr)[j + i * img->size_line_int] = 0x00ffff;
			j++;
		}
		i++;
	}
	free(pixel.entries);
}
