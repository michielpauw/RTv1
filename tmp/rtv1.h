/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 11:08:02 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/10 17:56:06 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# define IMG_W 1080
# define IMG_H 800
# define MAX_T_VALUE 50000
# define VEC_SIZE 3

# include "libft.h"
# include "libla.h"
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>

typedef struct	s_img
{
	void		*img_ptr;
	char		*img_arr;
	int			width;
	int			height;
	int			bpp;
	int			size_line;
	int			size_line_int;
	int			endian;
}				t_img;

typedef struct	s_event
{
	void		*mlx;
	void		*win;
	t_img		*img;
	char		*scene;
}				t_event;

typedef struct	s_xyz
{
	double		x;
	double		y;
	double		z;
}				t_xyz;

typedef struct	s_object
{
	int			id;
	int			type;
	double		radius;
	double		slope;
	double		(*f)();
	t_vector	color;
	t_vector	origin;
	t_vector	rotation;
	t_vector	normal;
}				t_object;

typedef struct	s_light
{
	t_vector	origin;
}				t_light;

typedef struct	s_camera
{
	t_vector	origin;
	t_vector	rotation;
}				t_camera;

typedef struct	s_scene
{
	char		*name;
	int			amount_obj;
	int			width;
	int			height;
	t_camera	camera;
	t_light		light;
	t_list		*objects;
}				t_scene;

void			error(int err);
void			s_error(const char *s);
void			set_scene(int fd, t_scene **scene);
void			set_object(t_list **objects, int id, int fd);
void			update_vector(int fd, t_vector *vector);
double			get_t_plane(t_object *s, t_vector *dir, t_vector *r_origin);
double			get_t_sphere(t_object *s, t_vector *dir, t_vector *r_origin);
double			get_t_cylinder(t_object *s, t_vector *dir, t_vector *r_origin);
double			get_t_cone(t_object *s, t_vector *dir, t_vector *r_origin);
double			*get_3d_entries(double x, double y, double z);
void			raytracer(t_event *event, t_scene *scene);
t_event			*init_window(char *scene);
t_vector		rotate_object(t_vector normal, t_vector rot);
void			init_loop(t_event *event);
int				key_pressed(int key, void *param);

#endif
