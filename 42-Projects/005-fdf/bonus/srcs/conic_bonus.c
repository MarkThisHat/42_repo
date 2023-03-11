/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conic_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:09:30 by maalexan          #+#    #+#             */
/*   Updated: 2023/03/10 16:33:40 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fdf.h"
#include "../incl/fdf_bonus.h"

static void	apply_cone(t_coord *coordin, double cx, double cy, double cz)
{
	double	c;
	double	d;
	double	dx;
	double	dy;
	double	dz;

	if (cx)
		c = cx;
	else if (cy)
		c = cy;
	else
		c = cz;
	dx = coordin->xyz[0] - cx;
	dy = coordin->xyz[1] - cy;
	dz = coordin->xyz[2] - cz;
	d = sqrt(dx * dx + dy * dy + dz * dz);
	coordin->xyz[0] = (d / (d + c)) * dx;
	coordin->xyz[1] = (d / (d + c)) * dy;
}

void	project_cone(t_mlxs *ms, double cx, double cy, double cz)
{
	int		i;
	int		j;

	i = 0;
	while (i < ms->col)
	{
		j = 0;
		while (j < ms->row)
		{
			apply_cone(&ms->cart[i][j], cx, cy, cz);
			j++;
		}
		i++;
	}
}

void	set_cone(t_mlxs *ms, double project, int axis)
{
	double	cx;
	double	cy;
	double	cz;

	cx = ms->remodel[4];
	cy = ms->remodel[5];
	cz = ms->remodel[6];
	if (axis == 0)
		cx = project;
	if (axis == 1)
		cy = project;
	if (axis == 2)
		cz = project;
	project_cone(ms, cx, cy, cz);
}

static int	cone_change(int model, int *ptr)
{
	ptr[4] = 0;
	ptr[5] = 0;
	ptr[6] = 0;
	if (!model)
		return ('Y');
	if (model == 'Y')
		return ('X');
	if (model == 'X')
		return ('z');
	if (model == 'z')
		return ('y');
	if (model == 'y')
		return ('x');
	return (0);
}

void	cone_mode(t_mlxs *ms, int mod)
{
	if (mod)
	{
		ms->remodel[7] = cone_change(ms->remodel[7], ms->remodel);
		return ;
	}
	if (!ms->remodel[7])
		set_cone(ms, 42, 2);
	else if (ms->remodel[7] == 'Y')
		set_cone(ms, 42, 1);
	else if (ms->remodel[7] == 'X')
		set_cone(ms, 42, 0);
	else if (ms->remodel[7] == 'z')
		set_cone(ms, -42, 2);
	else if (ms->remodel[7] == 'y')
		set_cone(ms, -42, 1);
	else if (ms->remodel[7] == 'x')
		set_cone(ms, -42, 0);
}