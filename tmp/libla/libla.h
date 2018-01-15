/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libla.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 08:10:54 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/10 17:32:45 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLA_H
# define LIBLA_H

# include "libft.h"
# include <math.h>

typedef struct	s_vector
{
	double	*entries;
	int		dim;
}				t_vector;

typedef struct	s_matrix
{
	int			rows;
	int			cols;
	double		**entries;
	double		det;
}				t_matrix;

t_matrix		*ft_matrix_mult(t_matrix m1, t_matrix m2);
t_matrix		*ft_get_zero_matrix(int rows, int cols);
double			ft_dot_product(t_vector *v1, t_vector *v2);
t_vector		*ft_v_add(t_vector *v1, t_vector *v2);
t_vector		*ft_v_scalar(t_vector *v, double s);
t_vector		*ft_m_to_v(t_matrix *m);
t_vector		*ft_lin_trans(t_vector *v, t_matrix *m);
t_vector		*ft_v_subtract(t_vector *v1, t_vector *v2);
t_vector		*ft_get_unit(int dir, int dim);
t_matrix		*ft_m_add(t_matrix *m1, t_matrix *m2);
t_matrix		*ft_m_scalar(t_matrix *m, double s);
t_matrix		*ft_transpose(t_matrix *m);
t_matrix		*ft_v_to_row_m(t_vector *v);
t_matrix		*ft_get_id_matrix(int dim);
t_matrix		*ft_get_3d_rot(int axis, double angle);
void			ft_set_det(t_matrix *m);
void			ft_free_matrix(t_matrix *m);
void			ft_free_vector(t_vector *v);

#endif
