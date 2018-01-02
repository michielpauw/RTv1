#include "libla.h"

t_vector	*ft_v_scalar(t_vector *v, double s)
{
	t_vector	*new_vector;
	int			i;

	if (!(new_vector = (t_vector *)malloc(sizeof(t_vector))))
		return (NULL);
	if (!(new_vector->entries = (double *)malloc(sizeof(double) * v->dim)))
		return (NULL);
	new_vector->dim = v->dim;
	i = 0;
	while (i < v->dim)
	{
		(new_vector->entries)[i] = (v->entries)[i] * s;
		i++;
	}
	return (new_vector);
}
