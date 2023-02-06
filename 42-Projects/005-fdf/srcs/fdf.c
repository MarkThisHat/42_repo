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
	main_struct.scale = ratioh / 2;
	if (ratiow < ratioh)
		main_struct.scale = ratiow / 2;
	mlx_setup(&main_struct);
//	draw_map(&main_struct);
//	mlx_put_image_to_window(main_struct.mlx, main_struct.win, main_struct.img1->img, 10, 10);
}

void	set_struct(t_mlxs *ms)
{
	ms->col = 0;
	ms->row = 0;
	ms->color = 0;
	ms->toggle = 0;
	ms->angle = 0.6154729;
	ms->focus = 100;
	ms->img2->img = NULL;
	ms->fad = &ms->img1;
//	ms->mlx = NULL;
//	ms->win = NULL;
//	ms->xy = NULL;
//	ms->img1->img = NULL;
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

	line.angle = ms->angle;
	x = 0;
	while (x < ms->row)
	{
		y = 0;
		while (y < ms->col)
		{
			if (ms->xy[x][y].color)
				(*ms->fad)->color = ms->xy[x][y].color;
			else
				(*ms->fad)->color = 0xFFFFFFFF;
			draw_row(ms, x, y, &line);
			draw_col(ms, x, y, &line);
			y++;
		}
		x++;
	}
}
/*
void	draw_row(t_mlxs *ms, int x, int y, t_line *l)
{
	if ((y + 1) == ms->col)
		return ;
	iso_zero(l, x, y, ms->xy[x][y].z);
	iso_one(l, x, y + 1, ms->xy[x][y + 1].z);
	l->x0 = l->x0 * ms->scale + ms->focus;
	l->x1 = l->x1 * ms->scale + ms->focus;
	l->y0 = l->y0 * ms->scale + ms->focus;
	l->y1 = l->y1 * ms->scale + ms->focus;
	put_line(ms, l);
	ft_printf("Draw Row x0: %i, x1: %i, y0: %i, y1:%i\n", l->x0, l->x1, l->y0, l->y1);
}

void	draw_col(t_mlxs *ms, int x, int y, t_line *l)
{
	if ((x + 1) == ms->row)
		return ;
	iso_zero(l, x, y, ms->xy[x][y].z);
	iso_one(l, x + 1, y, ms->xy[x + 1][y].z);
	l->x0 = l->x0 * ms->scale + ms->focus;
	l->x1 = l->x1 * ms->scale + ms->focus;
	l->y0 = l->y0 * ms->scale + ms->focus;
	l->y1 = l->y1 * ms->scale + ms->focus;
	put_line(ms, l);
	ft_printf("Draw Col x0: %i, x1: %i, y0: %i, y1:%i\n", l->x0, l->x1, l->y0, l->y1);
}
*/

int	isox(t_mlxs *ms, int x, int z)
{
		return (x + cos(ms->angle) * z);
}

int	isoy(t_mlxs *ms, int y, int z)
{
	return (y + sin(ms->angle) * z);
}

void	iso_zero(t_line *l, int x, int y, int z)
{
	l->x0 = x + cos(l->angle) * z - cos(l->angle) * y;
	l->y0 = -y * sin(l->angle) - z * sin(l->angle);
}

void	iso_one(t_line *l, int x, int y, int z)
{
	l->x1 = x + cos(l->angle) * z - cos(l->angle) * y;
	l->y1 = -y * sin(l->angle) - z * sin(l->angle);
}

	/* expression One
	*	destX = x + cos(angle) * z - cos(angle) * y;
	*	destY = -y * sin(angle) - z * sin(angle);
	*/
	/* expression two
	* destX = x + cos(angle) * z;
	* destY = y + sin(angle) * z;
	*/


void	draw_row(t_mlxs *ms, int x, int y, t_line *l)
{
	if ((y + 1) == ms->col)
		return ;
	l->x0 = (isox(ms, x, ms->xy[x][y].z) * ms->scale) + ms->focus;
	l->x1 = (isox(ms, x, ms->xy[x][y + 1].z) * ms->scale) + ms->focus;
	l->y0 = (isoy(ms, y, ms->xy[x][y].z) * ms->scale) + ms->focus;
	l->y1 = (isoy(ms, y + 1, ms->xy[x][y + 1].z) * ms->scale) + ms->focus;
	put_line(ms, l);
}

void	draw_col(t_mlxs *ms, int x, int y, t_line *l)
{
	if ((x + 1) == ms->row)
		return ;
	l->x0 = (isox(ms, x, ms->xy[x][y].z) * ms->scale) + ms->focus;
	l->x1 = (isox(ms, x + 1, ms->xy[x + 1][y].z) * ms->scale) + ms->focus;
	l->y0 = (isoy(ms, y, ms->xy[x][y].z) * ms->scale) + ms->focus;
	l->y1 = (isoy(ms, y, ms->xy[x + 1][y].z) * ms->scale) + ms->focus;
	put_line(ms, l);
}

/*
void	draw_row(t_mlxs *ms, int x, int y, t_line *l)
{
	if ((y + 1) == ms->col)
		return ;
	l->x0 = x * ms->scale + ms->focus;
	l->x1 = x * ms->scale + ms->focus;
	l->y0 = y * ms->scale + ms->focus;
	l->y1 = (y + 1) * ms->scale + ms->focus;
	put_line(ms, l);
	ft_printf("Draw Row x0: %i, x1: %i, y0: %i, y1:%i\n", l->x0, l->x1, l->y0, l->y1);
}

void	draw_col(t_mlxs *ms, int x, int y, t_line *l)
{
	if ((x + 1) == ms->row)
		return ;
	l->x0 = x * ms->scale + ms->focus;
	l->x1 = (x + 1) * ms->scale + ms->focus;
	l->y0 = y * ms->scale + ms->focus;
	l->y1 = y * ms->scale + ms->focus;
	put_line(ms, l);
	ft_printf("Draw Col x0: %i, x1: %i, y0: %i, y1:%i\n", l->x0, l->x1, l->y0, l->y1);
}

*/

void	mlx_setup(t_mlxs *ms)
{
	ms->mlx = mlx_init();
	ms->win = mlx_new_window(ms->mlx, WIN_W, WIN_H, "FDF");
	(*ms->fad)->img = mlx_new_image(ms->mlx, WIN_W, WIN_H);
	(*ms->fad)->addr = mlx_get_data_addr((*ms->fad)->img, &(*ms->fad)->bits_per_pixel, &(*ms->fad)->line_length, &(*ms->fad)->endian);
	mlx_hook(ms->win, 17, 0, &close_win, ms);
	mlx_hook(ms->win, 2, 1L<<0, keypress, ms);
	draw_map(ms);
	mlx_put_image_to_window(ms->mlx, ms->win, (*ms->fad)->img, 0, 0);
	mlx_loop(ms->mlx);
}
