/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:58:47 by maalexan          #+#    #+#             */
/*   Updated: 2023/03/07 11:13:25 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	copy_matrix(double src[4][4], double dest[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			dest[i][j] = src[i][j];
			j++;
		}
	i++;
	}
}

void	meld_matrix(t_mlxs *ms, double m1[4][4], double m2[4][4])
{
	int	i;
	int	j;
	double temp[4][4];

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			temp[i][j] = m1[i][0] * m2[0][j] + \
						m1[i][1] * m2[1][j] + \
						m1[i][2] * m2[2][j] + \
						m1[i][3] * m2[3][j];
			j++;
		}
	i++;
	}
	copy_matrix(temp, ms->matrix);
}
