/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 13:16:52 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/10 17:59:41 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		init_def_object(t_object *object, int id)
{
	t_vector	def;

	def.dim = 3;
	def.entries = get_3d_entries (0.0, 0.0, 0.0);
	object->id = id;
	object->type = 0;
	object->origin = def;
	def.entries = get_3d_entries (0.0, 0.0, 0.0);
	object->rotation = def;
	object->radius = 0.0;
	object->slope = 0.0;
	def.entries = get_3d_entries (0.0, 1.0, 0.0);
	object->color = def;
	def.entries = get_3d_entries (0.0, 1.0, 0.0);
	object->normal = def;
}

static void		set_det(t_object *object)
{
	object->normal = rotate_object(object->normal, object->rotation);
	if (object->type == 0)
		object->f = &get_t_plane;
	else if (object->type == 1)
		object->f = &get_t_sphere;
	else if (object->type == 2)
		object->f = &get_t_cylinder;
	else if (object->type == 3)
		object->f = &get_t_cone;
}

static double	get_radius_from_line(int fd)
{
	char	*line;
	double	to_return;

	if (get_next_line(fd, &line) != 1)
		error(0);
	if (*(line++) != '\t' || *(line++) != '\t')
		error(3);
	if (!ft_isdigit(*line))
		s_error("Radius must be a number.\n");
	to_return = ft_atod(line);
	if (to_return <= 0)
		s_error("Radius must be strictly positive");
	free(line - 2);
	return (to_return);
}

static int		get_object_type(int fd)
{
	char	*line;
	int		to_return;

	to_return = -1;
	if (get_next_line(fd, &line) != 1)
		error(0);
	if (*(line++) != '\t' || *(line++) != '\t')
		error(3);
	if (ft_strncmp(line, "plane", 5) == 0)
		to_return = 0;
	else if (ft_strncmp(line, "sphere", 6) == 0)
		to_return = 1;
	else if (ft_strncmp(line, "cylinder", 8) == 0)
		to_return = 2;
	else if (ft_strncmp(line, "cone", 4) == 0)
		to_return = 3;
	else
		s_error("Object type is not valid");
	free(line - 2);
	return (to_return);
}

void			set_object(t_list **objects, int id, int fd)
{
	char		*line;
	t_object	object;

	init_def_object(&object, id);
	while (get_next_line(fd, &line) == 1)
	{
		if (*line == '\0')
			break ;
		if (*line != '\t')
			error(3);
		line++;
		if (ft_strncmp(line, "type:", 5) == 0)
			object.type = get_object_type(fd);
		else if (ft_strncmp(line, "origin:", 7) == 0)
			update_vector(fd, &(object.origin));
		else if (ft_strncmp(line, "rotation:", 8) == 0)
			update_vector(fd, &(object.rotation));
		else if (ft_strncmp(line, "radius:", 7) == 0)
			object.radius = get_radius_from_line(fd);
		else if (ft_strncmp(line, "color:", 6) == 0)
			update_vector(fd, &(object.color));
		free(--line);
	}
	set_det(&object);
	free(line);
	ft_lstaddnewr(objects, &object, sizeof(object));
}
