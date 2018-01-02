#include "libla.h"

t_matrix	*ft_get_zero_matrix(int rows, int cols)
{
	t_matrix	*zero_matrix;
	int			i;
	int			j;

	if (!(zero_matrix = (t_matrix *)malloc(sizeof(t_matrix))))
		return (NULL);
	if (!(zero_matrix->entries = (double **)malloc(sizeof(double *) * rows)))
		return (NULL);
	zero_matrix->rows = rows;
	zero_matrix->cols = cols;
	i = -1;
	while (++i < rows)
	{
		if (!((zero_matrix->entries)[i] =
					(double *)malloc(sizeof(double) * cols)))
			return (NULL);
		j = -1;
		while (++j < cols)
			(zero_matrix->entries)[i][j] = (double)0.0;
	}
	return (zero_matrix);
}
