#include "libla.h"

t_matrix	*ft_transpose(t_matrix *m)
{
	t_matrix	*new_matrix;
	int			i;
	int			j;

	if (!(new_matrix = (t_matrix *)malloc(sizeof(t_matrix))))
		return (NULL);
	if (!(new_matrix->entries = (double **)malloc(sizeof(double *) * m->cols)))
		return (NULL);
	i = 0;
	new_matrix->cols = m->rows;
	new_matrix->rows = m->cols;
	while (i < m->cols)
	{
		j = 0;
		if (!((new_matrix->entries)[i] =
					(double *)malloc(sizeof(double) * m->rows)))
			return (NULL);
		while (j < m->rows)
		{
			(new_matrix->entries)[i][j] = (m->entries)[j][i];
			j++;
		}
		i++;
	}
	return (new_matrix);
}
