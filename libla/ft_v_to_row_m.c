#include "libla.h"

t_matrix	*ft_v_to_row_m(t_vector *v)
{
	t_matrix	*row_matrix;
	int			j;

	if (!(row_matrix = (t_matrix *)malloc(sizeof(t_matrix))))
		return (NULL);
	if (!(row_matrix->entries = (double **)malloc(sizeof(double *))))
		return (NULL);
	row_matrix->rows = 1;
	row_matrix->cols = v->dim;
	if (!((row_matrix->entries)[0] = 
				(double *)malloc(sizeof(double) * v->dim)))
			return (NULL);
	j = -1;
	while (++j < v->dim)
		(row_matrix->entries)[0][j] = (v->entries)[j];
	return (row_matrix);
}
