/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_v_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:25:02 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/11 14:27:43 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

double	ft_get_v_size(t_vector v)
{
	double	size;
	int		i;

	size = 0;
	i = 0;
	while (i < v.dim)
	{
		size += (v.entries)[i] * (v.entries)[i];
		i++;
	}
	size = sqrt(size);
	return (size);
}
