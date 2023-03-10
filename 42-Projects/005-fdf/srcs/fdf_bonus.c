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

int		key_rotation(int keycode, t_mlxs *ms)
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

int		key_shift(t_mlxs *ms, int keycode)
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

int		key_anchor(t_mlxs *ms, int keycode)
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

void	redraw_map(t_mlxs *ms)
{
	mlx_clear_window(ms->mlx, ms->win);
	clear_img(*ms->fad);
	fad_toggle(ms);
	draw_map(ms);
	mlx_put_image_to_window(ms->mlx, ms->win, (*ms->fad)->img, 0, 0);
	top_menu(ms);
}

void	top_menu(t_mlxs *ms)
{
	mlx_string_put(ms->mlx, ms->win, 125, 10, 0xFF0000, "MENU");
	mlx_string_put(ms->mlx, ms->win, 42, 30, 0xFF00FF, "Backspace key:");
	mlx_string_put(ms->mlx, ms->win, 150, 30, 0xFF, "Reset position");
	mlx_string_put(ms->mlx, ms->win, 42, 50, 0xFF00FF, "Arrow keys:");
	mlx_string_put(ms->mlx, ms->win, 150, 50, 0xFF, "Move Map");
	mlx_string_put(ms->mlx, ms->win, 42, 70, 0xFF00FF, "U and J keys:");
	mlx_string_put(ms->mlx, ms->win, 150, 70, 0xFF, "Rotate X axis");
	mlx_string_put(ms->mlx, ms->win, 42, 90, 0xFF00FF, "I and K keys:");
	mlx_string_put(ms->mlx, ms->win, 150, 90, 0xFF, "Rotate Y axis");
	mlx_string_put(ms->mlx, ms->win, 42, 110, 0xFF00FF, "O and L keys:");
	mlx_string_put(ms->mlx, ms->win, 150, 110, 0xFF, "Rotate Z axis");
	mlx_string_put(ms->mlx, ms->win, 42, 130, 0xFF00FF, "Z and X keys:");
	mlx_string_put(ms->mlx, ms->win, 150, 130, 0xFF, "Modify Z scale");
	mlx_string_put(ms->mlx, ms->win, 42, 150, 0xFF00FF, "Left click:");
	mlx_string_put(ms->mlx, ms->win, 150, 150, 0xFF, "Position Map");
	mlx_string_put(ms->mlx, ms->win, 42, 170, 0xFF00FF, "Right click:");
	mlx_string_put(ms->mlx, ms->win, 150, 170, 0xFF, "Conic project");
	mlx_string_put(ms->mlx, ms->win, 42, 190, 0xFF00FF, "Scroll or + - :");
	mlx_string_put(ms->mlx, ms->win, 150, 190, 0xFF, "Zoom in/out");
	mlx_string_put(ms->mlx, ms->win, 42, 210, 0xFF00FF, "R, G and B keys:");
	mlx_string_put(ms->mlx, ms->win, 150, 210, 0xFF, "Add respective color");
	bottom_menu(ms);
}

void bottom_menu(t_mlxs *ms)
{
	char *str;

	mlx_string_put(ms->mlx, ms->win, 80, WIN_H - 80, 0x00FF00, "TRANSLATION TABLE");
	mlx_string_put(ms->mlx, ms->win, 42, WIN_H - 60, 0xFF00FF, "Q and A keys:");
	mlx_string_put(ms->mlx, ms->win, 150, WIN_H - 60, 0x22FF, "Add/rem X -> ");
	str = ft_itoa(ms->translations[0]);
	mlx_string_put(ms->mlx, ms->win, 250, WIN_H - 60, 0xFFF04D, str);
	free(str);
	mlx_string_put(ms->mlx, ms->win, 42, WIN_H - 40, 0xFF00FF, "W and S keys:");
	mlx_string_put(ms->mlx, ms->win, 150, WIN_H - 40, 0x22FF, "Add/rem Y -> ");
	str = ft_itoa(ms->translations[1]);
	mlx_string_put(ms->mlx, ms->win, 250, WIN_H - 40, 0xFFF04D, str);
	free(str);
	mlx_string_put(ms->mlx, ms->win, 42, WIN_H - 20, 0xFF00FF, "E and D keys:");
	mlx_string_put(ms->mlx, ms->win, 150, WIN_H - 20, 0x22FF, "Add/rem Z -> ");
	str = ft_itoa(ms->translations[2]);
	mlx_string_put(ms->mlx, ms->win, 250, WIN_H - 20, 0xFFF04D, str);
	free(str);
}
