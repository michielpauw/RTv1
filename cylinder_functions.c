/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 10:37:47 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/12 14:17:23 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double	get_a_value(t_object *s, t_vector *dir)
{
	double		dot;
	t_vector	*scal;
	t_vector	*dif;

	dot = ft_dot_product(&(s->normal), dir);
	scal = ft_v_scalar(&(s->normal), dot);
	dif = ft_v_subtract(dir, scal);
	dot = ft_dot_product(dif, dif);
	ft_free_vector(scal);
	ft_free_vector(dif);
	return (dot);
}

static double	get_b_value(t_object *s, t_vector *dir, t_vector *dist)
{
	double		dot;
	t_vector	*scal_1;
	t_vector	*scal_2;
	t_vector	*dif_1;
	t_vector	*dif_2;

	dot = ft_dot_product(dist, &(s->normal));
	scal_1 = ft_v_scalar(&(s->normal), dot);
	dif_1 = ft_v_subtract(dist, scal_1);
	dot = ft_dot_product(&(s->normal), dir);
	scal_2 = ft_v_scalar(&(s->normal), dot);
	dif_2 = ft_v_subtract(dir, scal_2);
	dot = 2 * ft_dot_product(dif_1, dif_2);
	ft_free_vector(scal_1);
	ft_free_vector(scal_2);
	ft_free_vector(dif_1);
	ft_free_vector(dif_2);
	return (dot);
}

static double	get_c_value(t_object *s, t_vector *dist)
{
	double		dot;
	t_vector	*scal;
	t_vector	*dif;

	dot = ft_dot_product(dist, &(s->normal));
	scal = ft_v_scalar(&(s->normal), dot);
	dif = ft_v_subtract(dist, scal);
	dot = ft_dot_product(dif, dif) - s->radius * s->radius;
	return (dot);
}

double			get_t_cylinder(t_object *s, t_vector *dir, t_vector *r_origin)
{
	t_vector	*dist;
	double		a;
	double		b;
	double		c;
	double		d;

	if (s->type != 2)
		return (-1);
	dist = ft_v_subtract(r_origin, &(s->origin));
	a = get_a_value(s, dir);
	b = get_b_value(s, dir, dist);
	c = get_c_value(s, dist);
	d = b * b - 4 * a * c;
	ft_free_vector(dist);
	if (d < 0)
		return (-1);
	return (get_nearest_intersection(a, b, d));
}
