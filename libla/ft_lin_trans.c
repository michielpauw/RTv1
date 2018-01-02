#include "libla.h"

t_vector	*ft_lin_trans(t_vector *v, t_matrix *m)
{
	t_vector	*new_vector;

	if (v->dim != m->cols)
		return (NULL);
	if (!(new_vector = ft_m_to_v(ft_matrix_mult(m,
						ft_transpose(ft_v_to_row_m(v))))))
		return (NULL);
	return (new_vector);
}
