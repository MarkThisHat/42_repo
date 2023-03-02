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
	{
		ms->angle += 0.166666667;
		bonus_roll(ms, 0, 0.166666667);
		printf("axis +X: %f\n", ms->angle);
	}
	if (keycode == J_KEY)
	{
		ms->angle -= 0.166666667;
		bonus_roll(ms, 0, -0.166666667);
		printf("axis -X: %f\n", ms->angle);
	}
	if (keycode == I_KEY)
	{
		ms->angle += 0.166666667;
		bonus_roll(ms, 1, 0.166666667);
		printf("axis +Y: %f\n", ms->angle);
	}
	if (keycode == K_KEY)
	{
		ms->angle -= 0.166666667;
		bonus_roll(ms, 1, -0.166666667);
		printf("axis -Y: %f\n", ms->angle);
	}
	if (keycode == O_KEY)
	{
		ms->angle += 0.166666667;
		bonus_roll(ms, 2, 0.166666667);
		printf("axis +Z: %f\n", ms->angle);
	}
	if (keycode == L_KEY)
	{
		ms->angle -= 0.166666667;
		bonus_roll(ms, 2, -0.166666667);
		printf("axis -Z: %f\n", ms->angle);
	}
	if (keycode == N_PLU_K)
	{
		bonus_scale(ms, 1);
	}
	if (keycode == N_MIN_K)
	{
		bonus_scale(ms, 0);
	}
	if (keycode == BCKSPC)
	{
		reset_placement(ms);
	}
	if (keycode == ARW_U_K)
	{
		ms->height_adj -= 20;
	}
	if (keycode == ARW_D_K)
	{
		ms->height_adj += 20;
	}
	if (keycode == ARW_L_K)
	{
		ms->width_adj -= 20;
	}
	if (keycode == ARW_R_K)
	{
		ms->width_adj += 20;
	}
	if (keycode == R_KEY)
	{
		add_color(&ms->color, &ms->dye, 16);
	}
	if (keycode == G_KEY)
	{
		add_color(&ms->color, &ms->dye, 8);
	}
	if (keycode == B_KEY)
	{
		add_color(&ms->color, &ms->dye, 0);
	}
/*	if (keycode == Z_KEY)
		change_height(ms, 1);
	if (keycode == X_KEY)
		change_height(ms, -1);*/
	ft_printf("%i\n", keycode);
	mlx_clear_window(ms->mlx, ms->win);
	clear_img(*ms->fad);
	fad_toggle(ms);
	draw_map(ms);
	mlx_put_image_to_window(ms->mlx, ms->win, (*ms->fad)->img, 0, 0);
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

void	reset_placement(t_mlxs *ms)
{
	int	i;
	int	j;

	i = 0;
	while (i < ms->row)
	{
		j = 0;
		while (j < ms->col)
		{
			ms->cart[i][j].xyz[0] = i;
			ms->cart[i][j].xyz[1] = j;
			ms->cart[i][j].xyz[2] = ms->cart[i][j].z;
			j++;
		}
		i++;
	}
	ms->dye = 0;
	ms->color = 0xFFFFFFFF;
	crosswise_matrix(ms->matrix, ms->scale * 3, 0);
	ms->matrix[2][2] = ms->scale / 5.5;
	angle_matrix(ms, 2, -0.680678);//39 graus
	angle_matrix(ms, 0, -1.239184);//71 graus
	put_dot(ms, ms->matrix);
}

/*
void	change_height(t_mlxs *ms, int change)
{
	static int	new_z;
	int			i;
	int			j;

	i = 0;
	new_z += change;
	while (i < ms->row)
	{
		j = 0;
		while (j < ms->col)
		{
			ms->cart[i][j].xyz[0] = i;
			ms->cart[i][j].xyz[1] = j;
			ms->cart[i][j].xyz[2] = ms->cart[i][j].z + new_z;
			j++;
		}
		i++;
	}
	put_dot(ms, ms->matrix);
}
*/


/***\
if (keycode == P_KEY)
	{
		ms->angle += 0.1;
		//printf("%f\n", ms->angle);
	}
	if (keycode == O_KEY)
	{
		ms->angle -= 0.1;
		//printf("%f\n", ms->angle);
	}
	if (keycode == N_PLU_K)
		ms->scale -= 10;
	if (keycode == N_MIN_K)
		ms->scale += 10;
	if(keycode == ARW_U_K)
		ms->focus_x -= 10;
	if(keycode == ARW_D_K)
	{
		ms->focus_x += 10;
		ft_printf("focX%i\n", ms->focus_x);
	}
	if(keycode == ARW_L_K)
	{
		ms->focus_y -= 10;
		ft_printf("focY%i\n", ms->focus_y);
	}
	if(keycode == ARW_R_K)
		ms->focus_y += 10;
	if(keycode == K_KEY)
	{
		ms->tilt += 0.1;
		printf("%f\n", ms->tilt);
	}
	if(keycode == L_KEY)
	{
		ms->tilt -= 0.1;
		printf("%f\n", ms->tilt);
	}
	if(keycode == R_KEY)
		ms->color = 0xFFFF0000;
	if(keycode == G_KEY)
		ms->color = 0xFF00FF00;
	if(keycode == B_KEY)
		ms->color = 0xFF0000FF;
\***/