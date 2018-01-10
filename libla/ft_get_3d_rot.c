/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_3d_rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:50:02 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/10 17:44:06 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"
#include <stdio.h>
static void	set_entries(int axis, double angle, double ***entries)
{
	double		radians;

	radians = angle * 0.0174532925;
	(*entries)[axis][axis] = 1;
	(*entries)[(axis + 1) % 3][(axis + 1) % 3] = cos(radians);
	(*entries)[(axis + 2) % 3][(axis + 2) % 3] = cos(radians);
	(*entries)[(axis + 1) % 3][(axis + 2) % 3] = -sin(radians);
	(*entries)[(axis + 2) % 3][(axis + 1) % 3] = sin(radians);
}

t_matrix	*ft_get_3d_rot(int axis, double angle)
{
	t_matrix	*rot;

	if (!(rot = ft_get_zero_matrix(3, 3)))
		return (NULL);
	set_entries(axis, angle, &rot->entries);
	return (rot);
}
