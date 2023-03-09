/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:14:10 by maalexan          #+#    #+#             */
/*   Updated: 2023/03/08 17:14:19 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_placement(t_mlxs *ms, int change)
{
	int	i;
	int	j;

	translate_point(ms, 0, 0, 0);
	i = 0;
	while (i < ms->col)
	{
		j = 0;
		while (j < ms->row)
		{
			ms->cart[i][j].xyz[0] = i;
			ms->cart[i][j].xyz[1] = j;
			ms->cart[i][j].xyz[2] = ms->cart[i][j].z;
			j++;
		}
		i++;
	}
	ms->height_adj =  WIN_H / 6;
	ms->width_adj = WIN_W / 2;
	ms->dye = 0;
	ms->color = 0xFFFFFFFF;
	crosswise_matrix(ms->matrix, 1, 0);
	ms->matrix[2][2] += change;
	position_img(ms);
}

int		adjust_ambit(t_mlxs *ms, int height, int width)
{
	if (!width)
		return(height);
	if (!height)
		return (width);
	ms->height_adj = height;
	ms->width_adj = width;
	return (0);
}

void	bonus_roll(t_mlxs *ms, int axis, double amount)
{
	double	matrix[4][4];

	crosswise_matrix(matrix, 1, 0);
	rotation_matrix(matrix, axis, amount);
	put_dot(ms, matrix);
}

void	bonus_scale(t_mlxs *ms, int negative)
{
	double	scale;
	double	matrix[4][4];

	scale = 1.1;
	if (negative)
		scale = 0.9;
	crosswise_matrix(matrix, scale, 0);
	put_dot(ms, matrix);
}

void	change_height(t_mlxs *ms, int change)
{
	static int new_z;

	new_z += change;
	reset_placement(ms, new_z);
}