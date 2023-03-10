/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:37:28 by maalexan          #+#    #+#             */
/*   Updated: 2023/03/10 16:33:46 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fdf.h"
#include "../incl/fdf_bonus.h"

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
	position_img(&main_struct);
	mlx_setup(&main_struct);
}

void	mlx_fail(t_mlxs *ms, char *error, int mode)
{
	if (mode < 1)
		mlx_destroy_image(ms->mlx, ms->img1->img);
	if (mode < 0)
		mlx_destroy_window(ms->mlx, ms->win);
	mlx_destroy_display(ms->mlx);
	free(ms->mlx);
	free_close(ms, error, ms->col);
}

void	mlx_setup(t_mlxs *ms)
{
	ms->mlx = mlx_init();
	if (!ms->mlx)
		free_close(ms, "Couldn't start mlx\n", ms->col);
	ms->win = mlx_new_window(ms->mlx, WIN_W, WIN_H, "FDF");
	if (!ms->win)
		mlx_fail(ms, "Couldn't make a mlx window\n", 0);
	(*ms->fad)->img = mlx_new_image(ms->mlx, WIN_W, WIN_H);
	if (!(*ms->fad))
		mlx_fail(ms, "Couldn't make a mlx image\n", 1);
	(*ms->fad)->addr = mlx_get_data_addr(\
	(*ms->fad)->img, &(*ms->fad)->bits_per_pixel, \
	&(*ms->fad)->line_length, &(*ms->fad)->endian);
	mlx_hook(ms->win, 17, 0, &close_win, ms);
	mlx_hook(ms->win, 2, 1L << 0, keypress, ms);
	mlx_mouse_hook(ms->win, mouse_group, ms);
	draw_map(ms);
	mlx_put_image_to_window(ms->mlx, ms->win, \
	(*ms->fad)->img, WIN_W / WIN_W, WIN_H / WIN_H);
	top_menu(ms);
	mlx_loop(ms->mlx);
}

int	close_win(t_mlxs *ms)
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

int	keypress(int keycode, t_mlxs *ms)
{
	if (keycode == ESC_K)
		close_win(ms);
	else
		key_rotation(keycode, ms);
	return (keycode);
}
