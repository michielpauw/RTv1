/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_id_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 08:06:53 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/09 18:10:05 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_matrix	*ft_get_id_matrix(int dim)
{
	t_matrix	*id_matrix;
	int			i;

	if (!(id_matrix = (t_matrix *)malloc(sizeof(t_matrix))))
		return (NULL);
	if (!(id_matrix->entries = (double **)malloc(sizeof(double *) * dim)))
		return (NULL);
	i = 0;
	while (i < dim)
	{
		if (!((id_matrix->entries)[i] =
					(double *)malloc(sizeof(double) * dim)))
			return (NULL);
		(id_matrix->entries)[i][i] = (double)1.0;
		i++;
	}
	id_matrix->cols = dim;
	id_matrix->rows = dim;
	return (id_matrix);
}
