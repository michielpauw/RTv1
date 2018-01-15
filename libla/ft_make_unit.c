/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_unit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:23:50 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/11 15:20:35 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

void	ft_make_unit(t_vector *v)
{
	int		i;
	double	size;

	i = 0;
	size = ft_get_v_size(*v);
	if (size == 0)
		return ;
	while (i < v->dim)
	{
		(v->entries)[i] /= size;
		i++;
	}
}
