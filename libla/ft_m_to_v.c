/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m_to_v.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 08:07:08 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/09 18:00:44 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_vector	*ft_m_to_v(t_matrix *m)
{
	t_vector	*v;
	int			i;

	if (!(v = (t_vector *)malloc(sizeof(t_vector))))
		return (NULL);
	if (m->cols == 1)
		m = ft_transpose(m);
	if (m->rows != 1)
		return (NULL);
	if (!(v->entries = (double *)malloc(sizeof(double) * m->cols)))
		return (NULL);
	v->dim = m->cols;
	i = 0;
	while (i < m->cols)
	{
		(v->entries)[i] = (m->entries)[0][i];
		i++;
	}
	return (v);
}
