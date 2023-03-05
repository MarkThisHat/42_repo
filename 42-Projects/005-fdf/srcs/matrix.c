/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:58:47 by maalexan          #+#    #+#             */
/*   Updated: 2023/02/28 11:28:11 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dot_product(t_coord *c, double m[4][4])
{
	double	temp[3];

	temp[0] = c->xyz[0];
	temp[1] = c->xyz[1];
	temp[2] = c->xyz[2];

	temp[0] = c->xyz[0] * m[0][0] + c->xyz[1] * m[1][0] + c->xyz[2] * m[2][0] + 1 * m[3][0];
	temp[1] = c->xyz[0] * m[0][1] + c->xyz[1] * m[1][1] + c->xyz[2] * m[2][1] + 1 * m[3][1];
	temp[2] = c->xyz[0] * m[0][2] + c->xyz[1] * m[1][2] + c->xyz[2] * m[2][2] + 1 * m[3][2];

	c->xyz[0] = temp[0];
	c->xyz[1] = temp[1];
	c->xyz[2] = temp[2];
}

void	angle_matrix(t_mlxs *ms, int axis, double angle)
{
	double	matrix[4][4];

	crosswise_matrix(matrix, 1, 0);
	rotation_matrix(matrix, axis, angle);
	meld_matrix(ms, ms->matrix, matrix);
}

void	rotation_matrix(double matrix[4][4], int axis, double angle)
{
	if (axis == 0)
	{
		matrix[1][1] = cos(angle);
		matrix[1][2] = sin(angle);
		matrix[2][1] = -sin(angle);
		matrix[2][2] = cos(angle);
	}
	if (axis == 1)
	{
		
		matrix[0][0] = cos(angle);
		matrix[0][2] = -sin(angle);
		matrix[2][0] = sin(angle);
		matrix[2][2] = cos(angle);
	}
	if (axis == 2)
	{
		matrix[0][0] = cos(angle);
		matrix[0][1] = sin(angle);
		matrix[1][0] = -sin(angle);
		matrix[1][1] = cos(angle);
	}
}

void	crosswise_matrix(double matrix[4][4], double diag, double fill)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i != j)
				matrix[i][j] = fill;
			else
				matrix[i][j] = diag;
		j++;
		}
		i++;
	}
}

void	meld_matrix(t_mlxs *ms, double m1[4][4], double m2[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ms->matrix[i][j] = m1[i][0] * m2[0][j] + \
						m1[i][1] * m2[1][j] + \
						m1[i][2] * m2[2][j] + \
						m1[i][3] * m2[3][j];
			j++;
		}
	i++;
	}
}
