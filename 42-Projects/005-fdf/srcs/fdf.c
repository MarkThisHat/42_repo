/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:37:28 by maalexan          #+#    #+#             */
/*   Updated: 2023/02/22 18:05:14 by maalexan         ###   ########.fr       */
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
	int ratiow = WIN_W / main_struct.col;
	int ratioh = WIN_H / main_struct.row;
	main_struct.scale = ratioh / 3;
	if (ratiow < ratioh)
		main_struct.scale = ratiow / 3;
	mlx_setup(&main_struct);
}

void	set_struct(t_mlxs *ms)
{
	ms->col = 0;
	ms->row = 0;
	ms->color = 0xFFFFFFFF;
	ms->toggle = 42;
	ms->fad = &ms->img1;
	ms->img2->img = NULL;
	ms->angle = 0.955323;
	crosswise_matrix(ms->matrix, 30, 0);
	angle_matrix(ms, Z, 0.785398);
	angle_matrix(ms, X, 0.955323);
}

void	draw_map(t_mlxs *ms)
{
	t_line	line;
	int		x;
	int		y;

	x = 0;
	while (x < ms->row)
	{
		y = 0;
		while (y < ms->col)
		{
			if (ms->cart[x][y].color)
				(*ms->fad)->color = ms->cart[x][y].color;
			else
				(*ms->fad)->color = 0xFFFFFFFF;
			(*ms->fad)->color = see_color(ms, (*ms->fad)->color);
			if ((x + 1) != ms->row)
				draw_line(ms, ms->cart[x][y], ms->cart[x + 1][y], &line);
			if ((y + 1) != ms->col)
				draw_line(ms, ms->cart[x][y], ms->cart[x][y + 1], &line);
			y++;
		}
		x++;
	}
}

void	draw_line(t_mlxs *ms, t_coord ini, t_coord fin, t_line *l)
{
	l->x0 = ini.xyz[X];
	l->x1 = fin.xyz[X];
	l->y0 = ini.xyz[Y];
	l->y1 = fin.xyz[Y];
	put_line(ms, l);
}

void	mlx_setup(t_mlxs *ms)
{
	ms->mlx = mlx_init();
	ms->win = mlx_new_window(ms->mlx, WIN_W, WIN_H, "FDF");
	(*ms->fad)->img = mlx_new_image(ms->mlx, WIN_W, WIN_H);
	(*ms->fad)->addr = mlx_get_data_addr\
	((*ms->fad)->img, &(*ms->fad)->bits_per_pixel, \
	&(*ms->fad)->line_length, &(*ms->fad)->endian);
	mlx_hook(ms->win, 17, 0, &close_win, ms);
	mlx_hook(ms->win, 2, 1L<<0, keypress, ms);
	mlx_mouse_hook(ms->win, mouse_group, ms);
	draw_map(ms);
	mlx_put_image_to_window(ms->mlx, ms->win, (*ms->fad)->img, WIN_W / 3, WIN_H /3);
	mlx_loop(ms->mlx);
}
