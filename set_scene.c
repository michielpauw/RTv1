/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:41:28 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/31 15:32:33 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	init_def_scene(t_scene **scene)
{
	t_source	cam;

	if (!((*scene)->objects = ft_lstnew(NULL, 0)) ||
			!((*scene)->lights = ft_lstnew(NULL, 0)))
		error(1);
	(*scene)->name = "Default Scene";
	(*scene)->amount_obj = 0;
	(*scene)->amount_light = 0;
	(*scene)->width = 1080;
	(*scene)->height = 800;
	(*scene)->cam_set = 0;
	(*scene)->ambient = 0.5;
	cam.type = 0;
	cam.id = -1;
	cam.origin = ft_init_3v(CAM_X, CAM_Y, CAM_Z);
	cam.rotation = ft_zero_3v();
	cam.color = ft_init_3v(CAM_LIGHT_B, CAM_LIGHT_G, CAM_LIGHT_R);
	(cam.intensity).diff = 20;
	(cam.intensity).spec = 1;
	(*scene)->camera = cam;
}

void		set_scene(int fd, t_scene **scene)
{
	char		*line;

	init_def_scene(scene);
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_strncmp(line, "render {", 8) == 0)
			set_render(scene, fd);
		else if (ft_strncmp(line, "camera {", 8) == 0)
			set_camera(scene, fd);
		else if (ft_strncmp(line, "light {", 7) == 0)
			add_light(scene, fd);
		else if (ft_strncmp(line, "object {", 8) == 0)
			set_object(&((*scene)->objects), *scene,
					(*scene)->amount_obj, fd);
		free(line);
	}
	free(line);
}
