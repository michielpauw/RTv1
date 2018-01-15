/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 11:08:02 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/15 16:14:03 by mpauw            ###   ########.fr       */
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

typedef struct	s_object
{
	int			id;
	int			type;
	double		radius;
	double		(*f)();
	t_vector	color;
	t_vector	origin;
	t_vector	rotation;
	t_vector	normal;
	t_list		*rel_sources;
}				t_object;

typedef struct	s_source
{
	int			type;
	int			id;
	t_vector	origin;
	t_vector	rotation;
}				t_source;

typedef struct	s_scene
{
	char		*name;
	int			amount_obj;
	int			amount_src;
	int			amount_light;
	int			width;
	int			height;
	t_list		*sources;
	t_list		*objects;
}				t_scene;

void			error(int err);
void			s_error(const char *s);
void			set_scene(int fd, t_scene **scene);
void			set_object(t_list **objects, t_scene *scene, int id, int fd);
void			update_vector(int fd, t_vector *vector);
//double			get_t_plane(t_object *s, t_vector *dir, t_vector *r_origin);
//double			get_t_sphere(t_object *s, t_vector *dir, t_vector *r_origin);
//double			get_t_cylinder(t_object *s, t_vector *dir, t_vector *r_origin);
//double			get_t_cone(t_object *s, t_vector *dir, t_vector *r_origin);
//double			get_s_plane(t_object *s, t_vector *dir, t_vector *r_origin);
//double			get_s_sphere(t_object *s, t_vector *dir, t_vector *r_origin);
double			get_s_cylinder(t_object *s, t_vector *dir, t_vector *r_origin);
//double			get_s_cone(t_object *s, t_vector *dir, t_vector *r_origin);
double			*get_3d_entries(double x, double y, double z);
double			get_nearest_intersection(double a, double b, double d);
void			raytracer(t_event *event, t_scene *scene);
t_event			*init_window(char *scene);
void			rotate_object(t_object *object, t_scene *scene);
void			init_loop(t_event *event);
int				key_pressed(int key, void *param);

#endif
