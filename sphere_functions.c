/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:51:58 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/08 18:43:30 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double	get_nearest_intersection(double a, double b, double d)
{
	double	t_1;
	double	t_2;

	t_1 = (-b + sqrt(d)) / (2 * a);
	t_2 = (-b - sqrt(d)) / (2 * a);
	if (t_1 < 0.001 && t_2 < 0.001)
		return (-1);
	if (t_1 < 0.001)
		return (t_2);
	if (t_2 < 0.001)
		return (t_1);
	else
		return ((t_1 < t_2) ? t_1 : t_2);
}

double			get_t_sphere(t_object *s, t_vector *dir, t_vector *r_origin)
{
	t_vector	*dist;
	double		a;
	double		b;
	double		c;
	double		d;

	if (s->type != 1)
		return (-1);
	dist = ft_v_subtract(r_origin, &(s->origin));
	a = ft_dot_product(dir, dir);
	b = 2 * ft_dot_product(dir, dist);
	c = ft_dot_product(dist, dist) - s->radius * s->radius;
	d = b * b - 4 * a * c;
	if (d < 0)
	{
		return (-1);
	}
	return (get_nearest_intersection(a, b, d));
}
