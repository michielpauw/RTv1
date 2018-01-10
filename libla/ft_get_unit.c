/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_unit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:41:14 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/09 17:48:31 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_vector	*ft_get_unit(int dir, int dim)
{
	t_vector	*vector;
	int			i;

	if (!(vector = (t_vector *)malloc(sizeof(t_vector))))
		return (NULL);
	if (!(vector->entries = (double *)malloc(sizeof(double) * dim)))
		return (NULL);
	if (dir >= dim || dir < 0 || dim < 0)
		return (NULL);
	i = 0;
	vector->dim = dim;
	while (i < dim)
	{
		if (i == dir)
			(vector->entries)[i] = 1.0;
		else
			(vector->entries)[i] = 0;
		i++;
	}
	return (vector);
}
