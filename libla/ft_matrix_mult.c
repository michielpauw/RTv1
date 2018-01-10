/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_mult.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 08:07:11 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/09 19:49:12 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

static double	get_entry(t_matrix m1, t_matrix m2, int i, int j)
{
	int		r;
	double	entry;

	r = 0;
	entry = 0;
	while (r < m1.cols)
	{
		entry += (m1.entries)[i][r] * (m2.entries)[r][j];
		r++;
	}
	return (entry);
}

t_matrix		*ft_matrix_mult(t_matrix m1, t_matrix m2)
{
	t_matrix	*result;
	int			i;
	int			j;

	if (!(result = (t_matrix *)malloc(sizeof(t_matrix))))
		return (NULL);
	if (!(result->entries = (double **)malloc(sizeof(double *) * m1.rows)))
		return (NULL);
	if (m1.cols != m2.rows)
		return (NULL);
	result->rows = m1.rows;
	result->cols = m2.cols;
	i = -1;
	while (++i < m1.rows)
	{
		if (!(result->entries[i] = (double *)malloc(sizeof(double) * m2.cols)))
			return (NULL);
		j = -1;
		while (++j < m2.cols)
			(result->entries)[i][j] = get_entry(m1, m2, i, j);
	}
	return (result);
}
