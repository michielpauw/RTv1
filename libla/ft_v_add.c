#include "libla.h"

t_vector	*ft_v_add(t_vector *v1, t_vector *v2)
{
	t_vector	*new_vector;
	int			i;

	if (v1->dim != v2->dim)
		return (NULL);
	if (!(new_vector = (t_vector *)malloc(sizeof(t_vector))))
		return (NULL);
	if (!(new_vector->entries = (double *)malloc(sizeof(double) * v1->dim)))
		return (NULL);
	new_vector->dim = v1->dim;
	i = 0;
	while (i < v1->dim)
	{
		(new_vector->entries)[i] = (v1->entries)[i] + (v2->entries)[i];
		i++;
	}
	return (new_vector);
}
