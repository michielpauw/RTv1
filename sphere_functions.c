/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:51:58 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/12 14:17:38 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
	ft_free_vector(dist);
	if (d < 0)
		return (-1);
	return (get_nearest_intersection(a, b, d));
}
