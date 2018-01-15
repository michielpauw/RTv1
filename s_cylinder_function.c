/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_cylinder_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:10:52 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/15 16:12:41 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	get_s_cylinder(t_object *s, t_vector *dir, t_vector *src_o)
{
	double		a;
	double		b;
	double		c;
	double		d;

	if (s->type != 2)
		return (-1);
	a = ft_dot_product(dir, dir);
	b = 2 * ft_dot_product(dir, src_o);
	c = ft_dot_product(src_o, src_o) - s->radius * s->radius;
	d = b * b - 4 * a * c;
	if (d < 0)
		return (-1);
	return (get_nearest_intersection(a, b, d));
}
