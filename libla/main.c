#include "libla.h"
#include <stdio.h>

void	print_matrix(t_matrix *m)
{
	for (int i = 0; i < m->rows; i++)
	{
		for (int j = 0; j < m->cols; j++)
		{
			printf("%f ", (m->entries)[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void	print_vector(t_vector *v)
{
	for (int i = 0; i < v->dim; i++)
		printf("%f\n", (v->entries)[i]);
	printf("\n");
}

int	main(void)
{
	t_matrix	*zero_matrix;
	t_matrix	*id_matrix;
	t_matrix	*test_matrix;
	t_matrix	*test_2_matrix;
	t_vector	*test_vector;
	int			i;
	int			j;
	int			test_size;

	test_size = 5;

	test_vector = (t_vector *)malloc(sizeof(t_vector));
	test_vector->dim = test_size;
	(test_vector->entries) = (double *)malloc(sizeof(double) * test_size);
	test_2_matrix = (t_matrix *)malloc(sizeof(t_matrix));
	test_2_matrix->cols = test_size;
	test_2_matrix->rows = test_size;
	test_2_matrix->entries = (double **)malloc(sizeof(double *) * test_2_matrix->rows);
	i = -1;
	while (++i < test_size)
	{
		j = -1;
		(test_vector->entries)[i] = 1;
		(test_2_matrix->entries)[i] = (double *)malloc(sizeof(double) *test_2_matrix->cols);
		while (++j < test_size)
			(test_2_matrix->entries)[i][j] = 3 + i + j;
	}
	zero_matrix = ft_get_zero_matrix(4, test_size);
	zero_matrix = ft_transpose(zero_matrix);
	id_matrix = ft_get_id_matrix(test_size);
	zero_matrix = ft_matrix_mult(id_matrix, zero_matrix);
	test_matrix = ft_m_add(id_matrix, id_matrix);
	test_matrix = ft_m_scalar(id_matrix, 6);
	test_matrix = ft_matrix_mult(id_matrix, test_matrix);
	test_matrix = ft_m_add(test_2_matrix, test_matrix);
	test_matrix = ft_m_scalar(test_matrix, -1);
	print_matrix(test_matrix);
	ft_set_det(test_matrix);
	printf("%f\n\n", test_matrix->det);
	print_vector(ft_lin_trans(test_vector, test_matrix));
}
