/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 08:05:59 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/09 18:19:14 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

double	ft_dot_product(t_vector *v1, t_vector *v2)
{
	double	dot_product;
	int		i;

	dot_product = 0;
	i = 0;
	while (i < v1->dim)
	{
		dot_product += (v1->entries)[i] * (v2->entries)[i];
		i++;
	}
	return (dot_product);
}
