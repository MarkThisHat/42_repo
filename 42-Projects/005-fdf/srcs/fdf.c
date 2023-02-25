/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:37:28 by maalexan          #+#    #+#             */
/*   Updated: 2023/02/24 12:45:25 by maalexan         ###   ########.fr       */
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
	position_img(&main_struct);
	mlx_setup(&main_struct);
}

void	position_img(t_mlxs *ms)
{
	int		average;
	int		ratiow;
	int		ratioh;
	double	matrix[4][4];

	average = (ms->higher + ms->lower) / 2;
	ratiow = WIN_W / ms->col;
	ratioh = WIN_H / ms->row;
	ms->scale = ratioh / 3;
	if (ratiow < ratioh)
		ms->scale = ratiow / 3;
	if (!ms->scale)
		ms->scale = 1;
	ft_printf("avg: %i\nscl: %i\nratiow:%i\nratioh:%i\nhigher:%i\nlower %i\n", average, ms->scale, ratiow, ratioh, ms->higher, ms->lower);
	if (!average)
		average = 1;
	crosswise_matrix(matrix, ms->scale, 0);
	//matrix[3][3] = 1;
	matrix[4][4] = 1;
	meld_matrix(ms, ms->matrix, matrix);
	angle_matrix(ms, Z, -0.523599);
	angle_matrix(ms, Y, -0.615473);
	put_dot(ms, ms->matrix);
}

void	put_dot(t_mlxs *ms, double matrix[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < ms->row)
	{
		j = 0;
		while (j < ms->col)
		{
			dot_product(&ms->cart[i][j], matrix);
			j++;
		}
	i++;
	}
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
	ms->higher = 0;
	ms->lower = 0;
	crosswise_matrix(ms->matrix, 1, 0);
//	angle_matrix(ms, Z, -0.523599);
//	angle_matrix(ms, Y, -0.615473);
	/*angle_matrix(ms, Z, 0.785398);
	angle_matrix(ms, X, 0.955323);*/
	//angle_matrix(ms, Z, 0.785398);
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
	int	offset;

	offset = 100;
	l->x0 = ini.xyz[X] + offset;
	l->x1 = fin.xyz[X] + offset;
	l->y0 = ini.xyz[Y] + offset;
	l->y1 = fin.xyz[Y] + offset;
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
	mlx_put_image_to_window(ms->mlx, ms->win, (*ms->fad)->img, WIN_W / WIN_W, WIN_H / WIN_H);
	mlx_loop(ms->mlx);
}
