/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cross_product.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 10:59:19 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/12 11:15:52 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_vector	*ft_cross_product(t_vector v1, t_vector v2)
{
	t_vector	*cp;
	double		*e1;
	double		*e2;
	
	if (v1.dim != 3 || v2.dim != 3)
		return (NULL);
	if (!(cp = (t_vector *)malloc(sizeof(t_vector))))
		return (NULL);
	if (!(cp->entries = (double *)malloc(sizeof(double))))
		return (NULL);
	e1 = v1.entries;
	e2 = v2.entries;
	cp->dim = 3;
	(cp->entries)[0] = e1[1] * e2[2] - e2[1] * e1[2];
	(cp->entries)[1] = e1[2] * e2[0] - e2[2] * e1[0];
	(cp->entries)[2] = e1[0] * e2[1] - e2[0] * e1[1];
	return (cp);
}
