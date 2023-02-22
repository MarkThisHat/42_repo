/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:58:47 by maalexan          #+#    #+#             */
/*   Updated: 2023/02/22 18:02:55 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	maatrix(t_coord *c, int matrix[4][4])
{
	int	temp[3];

	temp[0] = c->xyz[0];
	temp[1] = c->xyz[1];
	temp[2] = c->xyz[2];

	temp[X] = c->xyz[X] * matrix[0][0] + c->xyz[Y] * matrix[1][0] + c->xyz[Z] * matrix[2][0];
	temp[Y] = c->xyz[X] * matrix[0][1] + c->xyz[Y] * matrix[1][1] + c->xyz[Z] * matrix[2][1];
	temp[Z] = c->xyz[X] * matrix[0][2] + c->xyz[Y] * matrix[1][2] + c->xyz[Z] * matrix[2][2];

	c->xyz[X] = temp[0];
	c->xyz[Y] = temp[1];
	c->xyz[Z] = temp[2];
}

void	x_angle_matrix(t_mlxs *ms)
{
	/*ms->matrix[0][0] = cos(ms->angle);
	ms->matrix[1][1] = cos(ms->angle);
	ms->matrix[1][0] = -sin(ms->angle);
	ms->matrix[0][1] = sin(ms->angle);*/
	ms->matrix[1][1] = cos(ms->angle);
	ms->matrix[2][2] = cos(ms->angle);
	ms->matrix[2][1] = -sin(ms->angle);
	ms->matrix[1][2] = sin(ms->angle);
}

void	scale_matrix(t_mlxs *ms, int diag, int fill)
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
				ms->matrix[i][j] = fill;
			else
				ms->matrix[i][j] = diag;
		j++;
		}
		i++;
	}
}

void	mult_matrix(t_mlxs *ms, int m1[4][4], int m2[4][4])
{
//	int	ms->matrix[4][4];
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
//	printma(prod);
}

void	apply_matrix(t_mlxs *ms, t_line *l)
{
	//x_angle_matrix(ms);
	l->x0 = l->x0 * ms->matrix[0][0] + l->y0 * ms->matrix[1][0];
	l->x1 = l->x1 * ms->matrix[0][0] + l->y1 * ms->matrix[1][0];
	l->y0 = l->x0 * ms->matrix[0][1] + l->y0 * ms->matrix[1][1];
	l->y1 = l->x1 * ms->matrix[0][1] + l->y1 * ms->matrix[1][1];
}


void	printma(int	matrix[4][4])
{
	for (int i = 0;i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
			ft_printf("%i\n", matrix[i][j]);
	}
}