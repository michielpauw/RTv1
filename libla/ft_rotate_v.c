/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_v.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:37:53 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/15 15:24:37 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

void	ft_rotate_v(t_vector *v, int axis, double angle, int rad)
{
	double	e[3];

	if (v->dim != 3)
		return ;
	if (!rad)
		angle = angle * RAD;
	e[0] = (v->entries)[0];
	e[1] = (v->entries)[1];
	e[2] = (v->entries)[2];
	(v->entries)[axis] = 1;
	(v->entries)[(axis + 1) % 3] = cos(angle) * e[(axis + 1) % 3]
		- sin(angle) * e[(axis + 1) % 3];
	(v->entries)[(axis + 2) % 3] = cos(angle) * e[(axis + 1) % 3]
		+ sin(angle) * e[(axis + 1) % 3];
}
