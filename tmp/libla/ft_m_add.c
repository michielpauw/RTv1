/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 08:07:03 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/09 17:54:29 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_matrix	*ft_m_add(t_matrix *m1, t_matrix *m2)
{
	t_matrix	*new_matrix;
	int			i;
	int			j;

	if (!(new_matrix = (t_matrix *)malloc(sizeof(t_matrix))))
		return (NULL);
	if (m1->rows != m2->rows || m1->cols != m2->cols)
		return (NULL);
	if (!(new_matrix->entries = (double **)malloc(sizeof(double *) * m1->rows)))
		return (NULL);
	i = -1;
	new_matrix->rows = m1->rows;
	new_matrix->cols = m1->cols;
	while (++i < m1->rows)
	{
		j = -1;
		if (!((new_matrix->entries)[i] =
					(double *)malloc(sizeof(double) * m1->cols)))
			return (NULL);
		while (++j < m1->cols)
			(new_matrix->entries)[i][j] = (m1->entries)[i][j] +
				(m2->entries)[i][j];
	}
	return (new_matrix);
}
