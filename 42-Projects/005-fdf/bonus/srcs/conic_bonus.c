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
