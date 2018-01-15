/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:46:56 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/10 17:57:37 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	rotate_object(t_vector normal, t_vector rot)
{
	int			i;
	t_matrix	*rot_matrix;
	t_vector	*tmp;

	i = 0;
	while (i < 3)
	{
		if (!(rot_matrix = ft_get_3d_rot(i, (rot.entries)[i])))
			error(2);
		if (!(tmp = ft_lin_trans(&normal, rot_matrix)))
			error(2);
		free(normal.entries);
		normal = *tmp;
		free(tmp);
		ft_free_matrix(rot_matrix);
		i++;
	}
	return (normal);
}
