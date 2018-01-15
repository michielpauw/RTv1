/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 13:57:58 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/12 14:16:50 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	*get_3d_entries(double x, double y, double z)
{
	double	*entries;

	if (!(entries = (double *)malloc(sizeof(double) * 3)))
		error(1);
	entries[0] = x;
	entries[1] = y;
	entries[2] = z;
	return (entries);
}

void	update_vector(int fd, t_vector *vector)
{
	char		**values_str;
	int			i;
	char		*line;

	if (get_next_line(fd, &line) != 1)
		error(0);
	if (*line != '\t' || *(line + 1) != '\t')
		error(3);
	values_str = ft_strsplit((line + 2), ' ');
	i = 0;
	while (*(values_str + i))
		i++;
	if (i != VEC_SIZE)
		s_error("Not the right amount of vector values");
	i = -1;
	while (++i < VEC_SIZE)
		(vector->entries)[i] = ft_atod(values_str[i]);
	ft_free_array((void **)values_str);
	free(line);
}

double	get_nearest_intersection(double a, double b, double d)
{
	double	t_1;
	double	t_2;

	t_1 = (-b + sqrt(d)) / (2 * a);
	t_2 = (-b - sqrt(d)) / (2 * a);
	if (t_1 < 0.001 && t_2 < 0.001)
		return (-1);
	if (t_1 < 0.001)
		return (t_2);
	if (t_2 < 0.001)
		return (t_1);
	else
		return ((t_1 < t_2) ? t_1 : t_2);
}
