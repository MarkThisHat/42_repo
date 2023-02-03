/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:37:28 by maalexan          #+#    #+#             */
/*   Updated: 2023/02/03 18:34:37 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

/*
typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct	s_coord {
	int		z;
	int		color;
}			t_coord;

typedef struct	s_vect {
	double	x;
	double	y;
	double	z;
}				t_vect

typedef struct	s_mlxs {
	void	*mlx;
	void	*win;
	t_img	*img1;
	t_img	*img2;
	t_coord	**xy;
	int		col;
	int		row;
	int		color;
	int		steep;
	int		gradient;
	int		toggle;
}			t_mlxs;

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
				if (ms->xy[i][j].color)
					ft_printf("Row: %i Col: %i has Z of: %i and Color of %i\n", i, j, ms->xy[i][j].z, ms->xy[i][j].color);
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
	mlx_setup(&main_struct);
//	draw_map(&main_struct);
//	mlx_put_image_to_window(main_struct.mlx, main_struct.win, main_struct.img1->img, 10, 10);
//	printmap(&main_struct);
}

void	draw_map(t_mlxs *ms)
{
	t_line	line;

	line.x0 = 50;
	line.x1 = 70;
	line.y0 = -120;
	line.y1 = 130;
	ms->img1->color = 0xFFFFFFFF;
	put_line(ms, &line);
	ft_printf("got to draw_map\n");
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
