#include "x_mini_struct.h"

void    add_vector(double a[], double b[], double sum_vect[])
{
	int	i;

	i = -1;
	while (++i < AXIS)
		sum_vect[i] = a[i] + b[i];
}

void	add_color(t_color *a, t_color *b, t_color *sum_color)
{
	int	i;

	i = -1;
	while (++i < AXIS)
		sum_color->rgb[i] = a->rgb[i] + b->rgb[i];
}

void	subtract_vector(double a[], double b[], double subt_vect[])
{
	int	i;

	i = -1;
	while (++i < AXIS)
		subt_vect[i] = a[i] - b[i];
}