#include "libla.h"

double	ft_dot_product(t_vector	*v1, t_vector *v2)
{
	double	dot_product;
	int		i;

	dot_product = 0;
	i = 0;
	while (i < v1->dim)
	{
		dot_product += (v1->entries)[i] * (v2->entries)[i];
		i++;
	}
	return (dot_product);
}
