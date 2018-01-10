/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:38:46 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/09 16:18:40 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	get_visible_object(double *t_value, t_vector *r_origin,
		t_vector *dir, t_list *objects)
{
	int			object_id;
	double		tmp;
	t_list		*tmp_list;
	t_object	*obj;

	tmp_list = objects;
	object_id = 0;
	while (tmp_list)
	{
		obj = (t_object *)tmp_list->content;
		tmp = obj->f(obj, dir, r_origin);
		if (tmp > 0 && tmp < *t_value)
		{
			*t_value = tmp;
			object_id = (obj->id);
		}
		tmp_list = tmp_list->next;
	}
	return (object_id);
}

static int	get_pixel_value(t_scene *scene, t_vector pixel)
{
	t_vector	*dir;
	t_list		*objects;
	double		t_value;
	int			object_id;

	dir = ft_v_subtract(&pixel, &((scene->camera).origin));
	objects = scene->objects;
	t_value = MAX_T_VALUE;
	object_id = -1;
	object_id = get_visible_object(&t_value, &((scene->camera).origin),
			dir, objects);
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
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(event->mlx, event->win, (event->img)->img_ptr, 0, 0);
}
