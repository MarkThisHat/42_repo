/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:44:21 by maalexan          #+#    #+#             */
/*   Updated: 2023/03/01 11:20:54 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"
#include <stdio.h>

int		keybonus(int keycode, t_mlxs *ms)
{
	if (keycode == U_KEY)
		bonus_roll(ms, 0, M_PI / 16);
	if (keycode == J_KEY)
		bonus_roll(ms, 0, -M_PI / 16);
	if (keycode == I_KEY)
		bonus_roll(ms, 1, M_PI / 16);
	if (keycode == K_KEY)
		bonus_roll(ms, 1, -M_PI / 16);
	if (keycode == O_KEY)
		bonus_roll(ms, 2, M_PI / 16);
	if (keycode == L_KEY)
		bonus_roll(ms, 2, -M_PI / 16);
	if (keycode == N_PLU_K)
		bonus_scale(ms, 1);
	if (keycode == N_MIN_K)
		bonus_scale(ms, 0);
	if (keycode == BCKSPC)
		reset_placement(ms, 0, 0, 0, 0);
	if (keycode == ARW_U_K)
		ms->height_adj -= adjust_ambit(ms, 20, 0);
	if (keycode == ARW_D_K)
		ms->height_adj += adjust_ambit(ms, 20, 0);
	if (keycode == ARW_L_K)
		ms->width_adj -= adjust_ambit(ms, 0, 20);
	if (keycode == ARW_R_K)
		ms->width_adj += adjust_ambit(ms, 0, 20);
	if (keycode == R_KEY)
		add_color(&ms->color, &ms->dye, 16);
	if (keycode == G_KEY)
		add_color(&ms->color, &ms->dye, 8);
	if (keycode == B_KEY)
		add_color(&ms->color, &ms->dye, 0);
	if (keycode == Z_KEY)
		change_height(ms, 1);
	if (keycode == X_KEY)
		change_height(ms, -1);
	redraw_map(ms);
	return (keycode);
}

void	fad_toggle(t_mlxs *ms)
{
	if (ms->toggle == 42)
	{
		ms->fad = &ms->img2;
		(*ms->fad)->img = mlx_new_image(ms->mlx, WIN_W, WIN_H);
		(*ms->fad)->addr = mlx_get_data_addr((*ms->fad)->img, &(*ms->fad)->bits_per_pixel, &(*ms->fad)->line_length, &(*ms->fad)->endian);
		ms->toggle = 0;
		return ;
	}
	if (!ms->toggle)
	{
		ms->fad = &ms->img1;
		ms->toggle = 1;
	}
	else
	{
		ms->fad = &ms->img2;
		ms->toggle = 0;
	}
}

void	clear_img(t_img *img)
{
	char			*painter;
	char			*target;

	target = img->addr + (WIN_H * img->line_length);
	painter = img->addr;
	while(painter < target + 1)
	{
		*(unsigned int*)painter = 0;
		painter++;
	}
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
	reset_placement(ms, new_z, 0, 0, 0);
}

void	reset_placement(t_mlxs *ms, int change, int tx, int ty, int tz)
{
	int	i;
	int	j;

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
	ms->height_adj =  WIN_H / 13;
	ms->width_adj = WIN_W / 2;
	ms->dye = 0;
	ms->color = 0xFFFFFFFF;
	crosswise_matrix(ms->matrix, 1, 0);
	ms->matrix[2][2] += change;
	position_img(ms, tx, ty, tz);
}

int		adjust_ambit(t_mlxs *ms, int height, int width)
{
	int	h;
	int	w;

	h = ms->height_adj;
	w = ms->width_adj;
	if (w > WIN_W + 500 || w < -(WIN_W / 2))
		return (width * (-10));
	if (h > WIN_H + 50 || h < -(WIN_H / 2))
		return(height * (-10));
	if (!width)
		return(height);
	if (!height)
		return (width);
	ms->height_adj = height - 400;
	ms->width_adj = width - 300;
	return (0);
}
