/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m_scalar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 08:07:05 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/09 18:00:06 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_matrix	*ft_m_scalar(t_matrix *m, double s)
{
	t_matrix	*new_matrix;
	int			i;
	int			j;

	if (!(new_matrix = (t_matrix *)malloc(sizeof(t_matrix))))
		return (NULL);
	if (!(new_matrix->entries = (double **)malloc(sizeof(double *) * m->rows)))
		return (NULL);
	i = 0;
	new_matrix->rows = m->rows;
	new_matrix->cols = m->cols;
	while (i < m->rows)
	{
		j = 0;
		if (!((new_matrix->entries)[i] =
					(double *)malloc(sizeof(double) * m->cols)))
			return (NULL);
		while (j < m->cols)
		{
			(new_matrix->entries)[i][j] = (m->entries)[i][j] * s;
			j++;
		}
		i++;
	}
	return (new_matrix);
}
