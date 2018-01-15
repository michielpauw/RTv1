/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 10:36:01 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/11 12:20:21 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	get_t_plane(t_object *s, t_vector *dir, t_vector *r_origin)
{
	t_vector	*normal;
	t_vector	*rot;
	double		t_value;

	//if (!(normal = ft_get_unit(2, 3)))
	//	error(2);
	rot = &(s->rotation);
	normal = &(s->normal);
	t_value = (ft_dot_product(&(s->origin), normal) - ft_dot_product(r_origin,
				normal)) / (ft_dot_product(dir, normal));
	if (t_value > 0.001)
		return (t_value);
	else
		return (-1.0);
}
