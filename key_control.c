/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 08:24:38 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/09 08:36:05 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		key_pressed(int key, void *param)
{
	t_event	*event;

	event = (t_event *)param;
	if (key == 53)
		exit(0);
	return (1);
}
