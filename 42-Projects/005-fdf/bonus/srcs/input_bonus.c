/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:44:21 by maalexan          #+#    #+#             */
/*   Updated: 2023/03/10 16:33:59 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fdf.h"
#include "../incl/fdf_bonus.h"

int	key_rotation(int keycode, t_mlxs *ms)
{
	if (keycode == BCKSPC)
		reset_placement(ms, 0);
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
	return (key_shift(ms, keycode));
}

int	key_shift(t_mlxs *ms, int keycode)
{
	if (keycode == ARW_U_K)
		ms->height_adj -= adjust_ambit(ms, 50, 0);
	if (keycode == ARW_D_K)
		ms->height_adj += adjust_ambit(ms, 50, 0);
	if (keycode == ARW_L_K)
		ms->width_adj -= adjust_ambit(ms, 0, 50);
	if (keycode == ARW_R_K)
		ms->width_adj += adjust_ambit(ms, 0, 50);
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
	return (key_anchor(ms, keycode));
}

int	key_anchor(t_mlxs *ms, int keycode)
{
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

int	mouse_group(int keycode, int x, int y, t_mlxs *ms)
{
	if (keycode == 1)
		adjust_ambit(ms, y, x);
	if (keycode == 4)
		bonus_scale(ms, 0);
	if (keycode == 5)
		bonus_scale(ms, 1);
	if (keycode == 3)
		project_cone(ms, 0, 0, 50);
	redraw_map(ms);
	return (keycode);
}
