#include "libla.h"

t_matrix	*ft_get_id_matrix(int dim)
{
	t_matrix	*id_matrix;
	int			i;

	if (!(id_matrix = ft_get_zero_matrix(dim, dim)))
		return (NULL);
	i = 0;
	while (i < dim)
	{
		(id_matrix->entries)[i][i] = (double)1.0;
		i++;
	}
	return (id_matrix);
}
