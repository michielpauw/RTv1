/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_det.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 08:06:49 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/09 17:46:05 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

static double	get_product(int arr[], t_matrix *m)
{
	double	to_return;
	int		i;

	to_return = 1;
	i = 0;
	while (i < m->rows)
	{
		to_return *= (m->entries)[arr[i]][i];
		i++;
	}
	return (to_return);
}

static void		permute(int arr[], int i, t_matrix *m, int sign)
{
	int	j;
	int	tmp;

	if (i == m->rows)
		m->det += sign * get_product(arr, m);
	j = i;
	while (j < m->rows)
	{
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
		if (i != j)
			sign *= -1;
		permute(arr, i + 1, m, sign);
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
		if (i != j)
			sign *= -1;
		j++;
	}
}

void			ft_set_det(t_matrix *m)
{
	int		i;
	int		arr[m->rows];

	i = -1;
	while (++i < m->rows)
		arr[i] = i;
	m->det = 0;
	if (m->rows != m->cols)
		return ;
	else
		permute(arr, 0, m, 1);
}
