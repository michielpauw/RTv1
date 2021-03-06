/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intensity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:40:06 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/31 18:16:51 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_3v		*get_normal(t_object *obj, t_3v point)
{
	t_3v	*norm_d;
	t_3v	*norm_t;
	double	size;

	if (obj->type == 0)
		return (ft_get_3_unit(1));
	norm_d = ft_3v_subtract(&point, &(obj->origin));
	norm_t = get_dir(*norm_d, obj->rotation);
	free(norm_d);
	if (obj->type == 2)
		(norm_t->v)[2] = 0;
	if (obj->type == 3)
		(norm_t->v)[2] = -((norm_t->v)[0] * (norm_t->v)[0]
			+ (norm_t->v)[1] * (norm_t->v)[1]) / (norm_t->v)[2];
	size = ft_get_3v_size(*norm_t);
	if (size == 0 && obj->type != 3)
		error(5);
	else if (size == 0)
	{
		free(norm_t);
		return (NULL);
	}
	ft_3v_scalar(norm_t, -1 / size);
	return (norm_t);
}

static double	get_s(t_3v point, t_3v *n, t_3v *dir_a, t_source cam)
{
	double	s;
	double	tmp;
	t_3v	*tmp_dir;
	t_3v	dir_v;

	s = 0;
	tmp = 2 * ft_3_dot_product(n, dir_a);
	dir_v = *n;
	ft_3v_scalar(&dir_v, tmp);
	tmp_dir = ft_3v_subtract(&dir_v, dir_a);
	dir_v = *tmp_dir;
	free(tmp_dir);
	tmp_dir = ft_3v_subtract(&point, &(cam.origin));
	s = ft_get_3v_size(*tmp_dir);
	ft_3v_scalar(tmp_dir, 1 / s);
	s = ft_3_dot_product(&dir_v, tmp_dir);
	free(tmp_dir);
	if (cos(tmp) >= 0.95 && cos(ft_3_dot_product(tmp_dir, n)) >= 0.95)
		return (0);
	return (s);
}

static double	get_d(t_3v *dir_a, t_3v *n, t_object *obj)
{
	double	d;
	double	size;
	double	angle;

	size = ft_get_3v_size(*dir_a);
	if (size == 0 && obj->type != 3)
		error(5);
	ft_3v_scalar(dir_a, 1 / size);
	size = ft_get_3v_size(*n);
	if (size == 0 && obj->type != 3)
		error(5);
	ft_3v_scalar(n, 1 / size);
	angle = ft_3_dot_product(n, dir_a);
	if (obj->type == 0)
		angle = fabs(angle);
	d = (obj->diffuse / M_PI) * angle;
	return (d);
}

t_intensity		get_intensity(t_3v point, t_object *obj, t_3v dir, t_source cam)
{
	t_3v		*n;
	t_3v		*dir_a;
	t_intensity	i;
	double		angle;

	i.diff = 0;
	i.spec = 0;
	if (!(n = get_normal(obj, point)) && obj->type != 3)
		error(1);
	else if (!n)
		return (i);
	dir_a = get_dir(dir, obj->rotation);
	i.diff = get_d(dir_a, n, obj);
	angle = get_s(point, n, dir_a, cam);
	if (angle < 0 && obj->type != 0)
		angle = 0;
	angle = fabs(angle);
	i.spec = obj->specular * pow(angle, obj->shininess);
	free(dir_a);
	free(n);
	return (i);
}
