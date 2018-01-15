/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lin_trans.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 08:07:00 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/10 16:44:01 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

/*
t_vector	*ft_lin_trans(t_vector *v, t_matrix *m)
{
	t_matrix	*lin_trans;
	t_matrix	*transposed;
	t_matrix	*row_m;
	t_vector	*to_return;

	if (v->dim != m->cols)
		return (NULL);
	if (!(row_m = ft_v_to_row_m(v)))
		return (NULL);
	ft_free_vector(v);
	if (!(transposed = ft_transpose(row_m)))
		return (NULL);
	ft_free_matrix(row_m);
	if (!(lin_trans = ft_matrix_mult(*m, *transposed)))
		return (NULL);
	ft_free_matrix(transposed);
	if (!(to_return = ft_m_to_v(lin_trans)))
		return (NULL);
	ft_free_matrix(lin_trans);
	return (to_return);
}
*/
t_vector	*ft_lin_trans(t_vector *v, t_matrix *m)
{
	t_vector	*to_return;
	int			i;
	int			j;
	double		entry;

	if (v->dim != m->cols)
		return (NULL);
	if (!(to_return = (t_vector *)malloc(sizeof(t_vector))))
		return (NULL);
	if (!(to_return->entries = (double *)malloc(sizeof(double) * m->rows)))
		return (NULL);
	to_return->dim = m->rows;
	i = -1;
	while (++i < m->rows)
	{
		entry = 0.0;
		j = -1;
		while (++j < v->dim)
			entry += (m->entries)[i][j] * (v->entries)[j];
		(to_return->entries)[i] = entry;
	}
	return (to_return);
}
