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
	double		*e_val;
	t_vector	*e_vec;
}				t_matrix;

t_matrix	*ft_matrix_mult(t_matrix *m1, t_matrix *m2);
t_matrix	*ft_get_zero_matrix(int rows, int cols);
double		ft_dot_product(t_vector	*v1, t_vector *v2);
t_vector	*ft_v_add(t_vector *v1, t_vector *v2);
t_vector	*ft_v_scalar(t_vector *v, double s);
t_vector	*ft_m_to_v(t_matrix *m);
t_vector	*ft_lin_trans(t_vector *v, t_matrix *m);
t_matrix	*ft_m_add(t_matrix *m1, t_matrix *m2);
t_matrix	*ft_m_scalar(t_matrix *m, double s);
t_matrix	*ft_transpose(t_matrix *m);
t_matrix	*ft_v_to_row_m(t_vector *v);
t_matrix	*ft_get_id_matrix(int dim);
void		ft_set_det(t_matrix *m);

#endif
