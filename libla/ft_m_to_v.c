#include "libla.h"

t_vector	*ft_m_to_v(t_matrix *m)
{
	t_vector	*v;
	int			i;

	if (m->cols == 1)
		m = ft_transpose(m);
	if (m->rows != 1)
		return (NULL);
	if (!(v = (t_vector *)malloc(sizeof(t_vector))))
		return (NULL);
	if (!(v->entries = (double *)malloc(sizeof(double) * m->cols)))
		return (NULL);
	v->dim = m->cols;
	i = 0;
	while (i < m->cols)
	{
		(v->entries)[i] = (m->entries)[0][i];
		i++;
	}
	return (v);
}
