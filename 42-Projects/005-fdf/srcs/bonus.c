/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:44:21 by maalexan          #+#    #+#             */
/*   Updated: 2023/03/07 11:03:37 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

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
		reset_placement(ms, 0);
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
	if (keycode == Q_KEY)
		translate_point(ms, 1, 0, 0);
	if (keycode == W_KEY)
		translate_point(ms, 0, 1, 0);
	if (keycode == E_KEY)
		translate_point(ms, 0, 0, 1);
	if (keycode == A_KEY)
		translate_point(ms, -1, 0, 0);
	if (keycode == S_KEY)
		translate_point(ms, 0, -1, 0);
	if (keycode == D_KEY)
		translate_point(ms, 0, 0, -1);				
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
