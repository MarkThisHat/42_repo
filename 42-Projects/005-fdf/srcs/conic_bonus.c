#include "fdf.h"

void	conic_sans(t_mlxs *ms, double cx, double cy, double cz)
{
	double	c;
	double	d;
	double	dx;
	double	dy;
	double	dz;
	int		i;
	int		j;
	if (cx)
		c = cx;
	else if (cy)
		c = cy;
	else
		c = cz;

	i = 0;
	while (i < ms->col)
	{
		j = 0;
		while ( j < ms->row)
		{
			dx = ms->cart[i][j].xyz[0] - cx;
			dy = ms->cart[i][j].xyz[1] - cy;
			dz = ms->cart[i][j].xyz[2] - cz;
			d = sqrt(dx * dx + dy * dy + dz * dz);
			ms->cart[i][j].xyz[0] = (d / (d + c)) * dx;
			ms->cart[i][j].xyz[1] = (d / (d + c)) * dy;
			j++;
		}
		i++;
	}
}
