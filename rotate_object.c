/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:46:56 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/15 16:41:00 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_source	change_rel_origin(t_source source, t_source o_source,
		t_object *obj)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		((source.origin).entries)[i] = ((o_source.origin).entries)[i] -
			((obj->origin).entries)[i];
		i++;
	}
	return (source);
}

static t_source	change_rel_source(t_source source, t_source o_source,
		t_object *obj)
{
	int			i;

	source = change_rel_origin(source, o_source, obj);
	i = 2;
	while (i >= 0)
	{
		ft_rotate_v(&(source.rotation), i, -((obj->rotation).entries)[i], 0);
		i--;
	}
	return (source);
}

static void		rotate_sources(t_object *object, t_scene *scene)
{
	t_source	source;
	t_source	*o_source;
	t_list		*lst;
	t_vector	*rot;

	lst = scene->sources;
	while (lst)
	{
		if (!((source.origin).entries = (double *)malloc(sizeof(double) * 3)))
			error(1);
		if (!(rot = ft_get_unit(2, 3)))
			error(1);
		source.rotation = *rot;
		o_source = (t_source *)(lst->content);
		source = change_rel_source(source, *o_source, object);
		ft_lstaddnewr(&(object->rel_sources), &source, sizeof(source));
		lst = lst->next;
	}
}

void		rotate_object(t_object *object, t_scene *scene)
{
	int			i;

	i = 0;
	if ((object->rotation).dim != 3 || (object->normal).dim != 3)
		s_error ("Vector not of length 3");
	if (!(object->rel_sources = ft_lstnew(NULL, 0)))
		error(1);
	while (i < 3)
	{
		ft_rotate_v(&(object->normal), i, ((object->rotation).entries)[i], 0);
		i++;
	}
	rotate_sources(object, scene);
}
