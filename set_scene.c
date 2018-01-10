/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 08:23:41 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/10 18:19:00 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	init_def_scene(t_scene **scene)
{
	t_vector	def;

	def.dim = 3;
	def.entries = get_3d_entries(200.0, 0.0, 0.0);	
	(*scene)->name = "Default Scene";
	(*scene)->amount_obj = 0;
	(*scene)->width = 1080;
	(*scene)->height = 800;
	((*scene)->camera).origin = def;
	def.entries = get_3d_entries(0.0, 0.0, 0.0);
	((*scene)->camera).rotation = def;
	def.entries = get_3d_entries(0.0, 0.0, 0.0);
	((*scene)->light).origin = def;
}

static void	set_cam_or_light(t_scene **scene, int fd, int light)
{
	char	*line;

	while (get_next_line(fd, &line) == 1)
	{
		if (*line == '\0')
			break ;
		if (*line != '\t')
			error(3);
		line++;
		if (ft_strncmp(line, "origin:", 7) == 0)
		{
			if (!light)
				update_vector(fd, &(((*scene)->camera).origin));
			else
				update_vector(fd, &(((*scene)->light).origin));
		}
		else if (ft_strncmp(line, "rotation:", 7) == 0 && !light)
			update_vector(fd, &(((*scene)->camera).rotation));
		free(--line);
	}
	free(line);
}

static void	set_name(t_scene **scene, int fd)
{
	char	*name;

	if (get_next_line(fd, &name) != 1)
		error(0);
	if (*name != '\t')
		error(3);
	name++;
	if (!ft_isprint((int)(*name)))
		s_error("The value of name must be printable");
	(*scene)->name = name;
}

static void	set_render(t_scene **scene, int fd)
{
	char	*line;
	char	*tmp;

	if (get_next_line(fd, &line) != 1)
		error(0);
	tmp = line;
	if (*line != '\t')
		error(3);
	if (ft_strncmp(line + 1, "dimensions:", 11) == 0)
	{
		free(tmp);
		if (get_next_line(fd, &line) != 1)
			error(0);
		if (*(line++) != '\t' || *(line++) != '\t')
			error(3);
		(*scene)->width = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
		(*scene)->height = ft_atoi(line);
	}
	free(tmp);
}

void		set_scene(int fd, t_scene **scene)
{
	char	*line;

	init_def_scene(scene);
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_strncmp(line, "name:", 5) == 0)
			set_name(scene, fd);
		else if (ft_strncmp(line, "camera:", 7) == 0 ||
				ft_strncmp(line, "light:", 6) == 0)
			set_cam_or_light(scene, fd, (*line == 'l') ? 1 : 0);
		else if (ft_strncmp(line, "object:", 7) == 0)
		{
			(*scene)->amount_obj++;
			set_object(&((*scene)->objects),
					(*scene)->amount_obj, fd);
		}
		else if (ft_strncmp(line, "render:", 7) == 0)
			set_render(scene, fd);
		free(line);
	}
	free(line);
}
