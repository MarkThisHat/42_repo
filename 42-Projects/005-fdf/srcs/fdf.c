/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:37:28 by maalexan          #+#    #+#             */
/*   Updated: 2023/03/07 12:26:21 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

int	main(int argc, char **argv)
{
	t_mlxs	main_struct;
	t_img	image;
	t_img	image2;

	set_struct(&main_struct, &image, &image2);
	main_struct.img1 = &image;
	main_struct.img2 = &image2;
	validate_usage(argc, argv, &main_struct);
	parse_map(&main_struct, argv[1]);
	position_img(&main_struct, 100, 100, 100);
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
