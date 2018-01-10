/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 08:05:39 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/10 18:19:38 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	error(int err)
{
	if (errno != 0)
		perror("Error");
	else
	{
		if (err == 0)
			ft_putstr_fd("Error: Error reading file\n", 2);
		else if (err == 1)
			ft_putstr_fd("Error: Error in memory allocation\n", 2);
		else if (err == 2)
			ft_putstr_fd("Error: NULL returned\n", 2);
		else if (err == 3)
			ft_putstr_fd("Error: Values must be properly tabulated.\n", 2);
	}
	exit(1);
}

void	s_error(const char *s)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	usage(void)
{
	ft_putstr("You must enter a valid file name\n");
	exit(0);
}

/*
void	print_all_values(t_scene *scene)
{
	t_camera	camera;
	t_light		light;
	t_object	*obj;
	t_list		*lst;
	t_xyz		coor;
	int			id;

	camera = scene->camera;
	light = scene->light;
	lst = (t_list *)(scene->objects);
	obj = (t_object *)lst->content;
	printf("Sizeof object: %lu\n", sizeof(*obj));
	printf("Name: %s\n", scene->name);
	printf("Amount of objects: %d\n", scene->amount_obj);
	printf("Width: %d\n", scene->width);
	printf("Height: %d\n", scene->height);
	coor = camera.rotation;
	printf("Camera rotation: %f %f %f\n", coor.x, coor.y, coor.z);
	coor = camera.origin;
	printf("Camera origin: %f %f %f\n", coor.x, coor.y, coor.z);
	coor = light.origin;
	printf("Light origin: %f %f %f\n", coor.x, coor.y, coor.z);
	coor = light.origin;
	printf("Light origin: %f %f %f\n", coor.x, coor.y, coor.z);
	id = obj->id;
	coor = obj->color;
	printf("Obj color: %f %f %f\n", coor.x, coor.y, coor.z);
}
*/
/*
t_vector	*leak_test(void)
{
	t_matrix	*matrix;
	t_vector	*vector;
	t_vector	*lin_trans;

	if (!(vector = (t_vector *)malloc(sizeof(t_vector))))
		error(1);
	if (!(vector->entries = (double *)malloc(sizeof(double) * 3)))
		error(1);
	matrix = ft_get_3d_rot(0.1, 0.1, 0.1);
	(vector->entries)[0] = 1.0;
	(vector->entries)[1] = 0.0;
	(vector->entries)[2] = 0.0;
	vector->dim = 3;
	lin_trans = ft_lin_trans(vector, matrix);
	printf("%p\n", (void *)vector);
	return (lin_trans);
}
*/
int		main(int argc, char **argv)
{
	int		fd;
	t_scene	*scene;
	t_event	*event;

	errno = 0;
	if (argc != 2)
		usage();
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		error(0);
	if (!(scene = (t_scene *)malloc(sizeof(t_scene))) ||
			!(scene->objects = ft_lstnew(NULL, 0)))
		error(2);
	set_scene(fd, &scene);
	event = init_window(scene->name);
	raytracer(event, scene);
	init_loop(event);
}
