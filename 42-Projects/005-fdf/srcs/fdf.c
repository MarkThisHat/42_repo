/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:37:28 by maalexan          #+#    #+#             */
/*   Updated: 2023/03/07 11:13:16 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

int	main(int argc, char **argv)
{
	t_mlxs	main_struct;
	t_img	image;
	t_img	image2;

	main_struct.img1 = &image;
	main_struct.img2 = &image2;
	set_struct(&main_struct);
	validate_usage(argc, argv, &main_struct);
	parse_map(&main_struct, argv[1]);
	position_img(&main_struct, 0, 0, 0);
	mlx_setup(&main_struct);
}

void	mlx_setup(t_mlxs *ms)
{
	ms->mlx = mlx_init();
	ms->win = mlx_new_window(ms->mlx, WIN_W, WIN_H, "FDF");
	(*ms->fad)->img = mlx_new_image(ms->mlx, WIN_W, WIN_H);//int	mlx_mouse_get_pos(void *mlx_ptr, void *win_ptr, int *x, int *y);
	(*ms->fad)->addr = mlx_get_data_addr\
	((*ms->fad)->img, &(*ms->fad)->bits_per_pixel, \
	&(*ms->fad)->line_length, &(*ms->fad)->endian);
	mlx_hook(ms->win, 17, 0, &close_win, ms);
	mlx_hook(ms->win, 2, 1L<<0, keypress, ms);
	mlx_mouse_hook(ms->win, my_mouse_hook, ms);
	mlx_mouse_hook(ms->win, mouse_group, ms);
	draw_map(ms);
	mlx_put_image_to_window(ms->mlx, ms->win, (*ms->fad)->img, WIN_W / WIN_W, WIN_H / WIN_H);
	mlx_loop(ms->mlx);
}

int		close_win(t_mlxs *ms)
{
	if (ms->toggle == 42)
		mlx_destroy_image(ms->mlx, (*ms->fad)->img);
	else
	{
		mlx_destroy_image(ms->mlx, ms->img1->img);
		mlx_destroy_image(ms->mlx, ms->img2->img);
	}
	mlx_destroy_window(ms->mlx, ms->win);
	mlx_destroy_display(ms->mlx);
	free(ms->mlx);
	free_close(ms, 0, ms->col);
	return (1);	
}

void	free_close(t_mlxs *ms, char *str, int col)
{
	while(col)
	{
		col--;
		free(ms->cart[col]);
	}
	if(ms->cart)
		free(ms->cart);
	if (!str)
		leave_program(0, 0, 0);
	leave_program(str, 2, 5);
}

int		mouse_group(int keycode, int x, int y, t_mlxs *ms)
{
	ft_printf("k: %i x: %i y: %i\n", keycode, x, y);
	int	xm;
	int	ym;

	xm = 0;
	ym = 0;
	if (keycode == 1)
		adjust_ambit(ms, y, x);
	if (keycode == 4)
		bonus_scale(ms, 0);
	if (keycode == 5)
		bonus_scale(ms, 1);
	if (keycode == 3)
		translate_point(ms, x, y);
	redraw_map(ms);
	mlx_mouse_get_pos(ms->mlx, ms->win, &xm, &ym);
	ft_printf("x:%i\ny:%i\n", xm, ym);
//	int	mlx_mouse_move(void *mlx_ptr, void *win_ptr, int x, int y);
//	https://codebrowser.dev/qt5/include/X11/X.h.html
//	https://github.com/D-Programming-Deimos/libX11/blob/master/c/X11/keysymdef.h
	return (keycode + x + y);
}

void	redraw_map(t_mlxs *ms)
{
	mlx_clear_window(ms->mlx, ms->win);
	clear_img(*ms->fad);
	fad_toggle(ms);
	draw_map(ms);
	mlx_put_image_to_window(ms->mlx, ms->win, (*ms->fad)->img, 0, 0);
}

int		keypress(int keycode, t_mlxs *ms)
{
	if (keycode == ESC_K)
		close_win(ms);
	else
		keybonus(keycode, ms);
	return (keycode);
}

void	translate_point(t_mlxs *ms, int x, int y)
{
	double	matrix[4][4];

	crosswise_matrix(matrix, 1, 0);
	matrix[3][1] = x / 500;
	matrix[3][2] = y / 500;
//	meld_matrix(ms, ms->matrix, matrix);
	put_dot(ms, matrix);
}