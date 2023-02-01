#include "../incl/fdf.h"

int invert_endian(int color)
{
	int transp;
	int red;
	int green;
	int blue;

	blue = color & 0xFF000000;
	green = color & 0x00FF0000;
	red = color & 0x0000FF00;
	transp = color & 0x000000FF;
	color = (transp << 24) + (red << 8) + (green >> 8) + (blue >> 24);
	return (color);
}

void	swap(double *a, double *b)
{
	double temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

double	get_fract(double n)
{
	return (ceil(n) - n);
}
