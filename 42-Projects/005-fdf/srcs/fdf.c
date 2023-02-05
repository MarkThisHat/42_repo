/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:37:28 by maalexan          #+#    #+#             */
/*   Updated: 2023/02/04 21:29:59 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

/*
void	printmap(t_mlxs *ms)
{
	int i;
	int j;

	i = 0;
	while (i < ms->row)
	{
		j = 0;
		{
			while (j < ms->col)
			{
				//if (ms->xy[i][j].color)
			//		ft_printf("Row: %i Col: %i has Z of: %i and Color of %i\n", i, j, ms->xy[i][j].z, ms->xy[i][j].color);
			//ft_printf("%i\n", ms->xy[0][18].z);
				j++;
			}
		}
		i++;
	}
}
*/

int	main(int argc, char **argv)
{
	t_mlxs	main_struct;
	t_img	image;

	main_struct.img1 = &image;
	set_struct(&main_struct);
	validate_usage(argc, argv, &main_struct);
	parse_map(&main_struct, argv[1]);
	//printmap(&main_struct);
	int ratiow = WIN_W / main_struct.col;
	int ratioh = WIN_H / main_struct.row;
	main_struct.scale = ratioh;
	if (ratiow < ratioh)
		main_struct.scale = ratiow;
	mlx_setup(&main_struct);
//	draw_map(&main_struct);
//	mlx_put_image_to_window(main_struct.mlx, main_struct.win, main_struct.img1->img, 10, 10);
}
/*
void	draw_map(t_mlxs *ms)
{
	t_line	line;
	int		i;
	int		j;

	j = 0;
	while (j < ms->row)
	{
		i = 0;
		while (i < ms->col)
		{
			if (ms->xy[i][j].color)
				ms->img1->color = ms->xy[i][j].color;
			else
				ms->img1->color = 0xFFFFFFFF;
			draw_row(ms, j, i, &line);
			i++;
		}
		j++;
	}
}
*/
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
			if (ms->xy[x][y].color)
				ms->img1->color = ms->xy[x][y].color;
			else
				ms->img1->color = 0xFFFFFFFF;
			draw_col(ms, x, y, &line);
			draw_row(ms, x, y, &line);
			y++;
		}
		x++;
	}
}

void	draw_col(t_mlxs *ms, int x, int y, t_line *l)
{
	if ((y + 1) == ms->col)
		return ;
	l->x0 = x * ms->scale;
	l->x1 = x * ms->scale;
	l->y0 = y * ms->scale;
	l->y1 = (y + 1) * ms->scale;
	put_line(ms, l);
}

void	draw_row(t_mlxs *ms, int x, int y, t_line *l)
{
	if ((x + 1) == ms->row)
		return ;
	l->x0 = x * ms->scale;
	l->x1 = (x + 1) * ms->scale;
	l->y0 = y * ms->scale;
	l->y1 = y * ms->scale;
	put_line(ms, l);
}

void	mlx_setup(t_mlxs *ms)
{
	ms->mlx = mlx_init();
	ms->win = mlx_new_window(ms->mlx, WIN_W, WIN_H, "FDF");
	ms->img1->img = mlx_new_image(ms->mlx, WIN_W, WIN_H);
	ms->img1->addr = mlx_get_data_addr(ms->img1->img, &ms->img1->bits_per_pixel, &ms->img1->line_length, &ms->img1->endian);
	mlx_hook(ms->win, 17, 0, &close_win, ms);
	mlx_hook(ms->win, 2, 1L<<0, keypress, ms);
	draw_map(ms);
	mlx_put_image_to_window(ms->mlx, ms->win, ms->img1->img, 10, 10);
	mlx_loop(ms->mlx);
}
