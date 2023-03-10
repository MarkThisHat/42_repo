/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:25:45 by maalexan          #+#    #+#             */
/*   Updated: 2023/03/10 15:05:56 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dot_product(t_coord *c, double m[4][4])
{
	double	temp[3];

	temp[0] = c->xyz[0];
	temp[1] = c->xyz[1];
	temp[2] = c->xyz[2];
	temp[0] = c->xyz[0] * m[0][0] + c->xyz[1] * m[1][0] + \
	c->xyz[2] * m[2][0] + 1 * m[3][0];
	temp[1] = c->xyz[0] * m[0][1] + c->xyz[1] * m[1][1] + \
	c->xyz[2] * m[2][1] + 1 * m[3][1];
	temp[2] = c->xyz[0] * m[0][2] + c->xyz[1] * m[1][2] + \
	c->xyz[2] * m[2][2] + 1 * m[3][2];
	c->xyz[0] = temp[0];
	c->xyz[1] = temp[1];
	c->xyz[2] = temp[2];
}

void	put_dot(t_mlxs *ms, double matrix[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < ms->col)
	{
		j = 0;
		while (j < ms->row)
		{
			dot_product(&ms->cart[i][j], matrix);
			j++;
		}
	i++;
	}
}

void	translate_point(t_mlxs *ms, int x, int y, int z)
{
	double		matrix[4][4];
	static int	tx;
	static int	ty;
	static int	tz;

	tx += x;
	ty += y;
	tz += z;
	if (!x && !y && !z)
	{
		tx = 0;
		ty = 0;
		tz = 0;
	}
	crosswise_matrix(matrix, 1, 0);
	matrix[3][0] = tx;
	matrix[3][1] = ty;
	matrix[3][2] = tz;
	ms->remodel[0] = tx;
	ms->remodel[1] = ty;
	ms->remodel[2] = tz;
	put_dot(ms, matrix);
}

void	coord_calibrate(t_mlxs *ms, t_coord *cart, int i, int j)
{
	cart->xyz[0] = i;
	cart->xyz[1] = j;
	cart->xyz[2] = cart->z;
	if (ms->higher < cart->z)
		ms->higher = cart->z;
	if (ms->lower > cart->z)
		ms->lower = cart->z;
}