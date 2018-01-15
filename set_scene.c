/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 08:23:41 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/15 16:43:07 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	init_def_scene(t_scene **scene)
{
	t_vector	def;

	def.dim = 3;
	(*scene)->name = "Default Scene";
	(*scene)->amount_obj = 0;
	(*scene)->amount_src = 0;
	(*scene)->amount_light = 0;
	(*scene)->width = 1080;
	(*scene)->height = 800;
}

static void	set_source(t_scene **scene, int fd, int type)
{
	t_source	source;
	char		*line;

	if (!((source.origin).entries = (double *)malloc(sizeof(double) * 3)) || 
			!((source.rotation).entries = (double *)malloc(sizeof(double) * 3)))
		error(1);
	source.id = (*scene)->amount_obj;
	source.type = type;
	(*scene)->amount_light += type;
	(*scene)->amount_src++;
	while (get_next_line(fd, &line) == 1)
	{
		if (*line == '\0')
			break ;
		if (*line != '\t')
			error(3);
		if (ft_strncmp(line + 1, "origin:", 7) == 0)
			update_vector(fd, &(source.origin));
		else if (ft_strncmp(line + 1, "rotation:", 7) == 0 && !type)
			update_vector(fd, &(source.rotation));
		free(line);
	}
	free(line);
	ft_lstaddnewr(&((*scene)->sources), &source, sizeof(source));
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
		else if (ft_strncmp(line, "camera:", 7) == 0)
			set_source(scene, fd, 1);
		else if (ft_strncmp(line, "light:", 6) == 0)
			set_source(scene, fd, 0);
		else if (ft_strncmp(line, "object:", 7) == 0)
		{
			(*scene)->amount_obj++;
			set_object(&((*scene)->objects), *scene,
					(*scene)->amount_obj, fd);
		}
		else if (ft_strncmp(line, "render:", 7) == 0)
			set_render(scene, fd);
		free(line);
	}
	free(line);
	if ((*scene)->amount_src - (*scene)->amount_light != 1)
		s_error("Exactly one camera expected");
}
