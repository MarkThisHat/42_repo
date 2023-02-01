/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:37:28 by maalexan          #+#    #+#             */
/*   Updated: 2023/01/30 21:44:27 by maalexan         ###   ########.fr       */
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

int		keypress(int keycode, t_mlxs *ms)
{
	if (keycode == ESC_K)
		close_win(ms);
	return (keycode);
}

int		draw_map(t_mlxs *ms)
{
	int		i;
	int		j;
	int		mult;
//	double	angle;

	i = 0;
	j = 0;
//	angle = 0.615473; //rad 0.615473 deg 35.264
	mult = 1.2;
	while (i < ms->row)
	{
		j = 0;
		while (j < ms->col - 1)
		{
			if (ms->xy[i][j].color)
				ms->color = ms->xy[i][j].color;
			plot_line(ms, (j * mult), ((j + 1) * mult), (i * mult), (i * mult));
			j++;
		}
		i++;
	}
	i = 0;
	while (i < ms->col)
	{
		j = 0;
		while (j < ms->row - 1)
		{
			if (ms->xy[i][j].color)
				ms->color = ms->xy[i][j].color;
			//plot_liney(ms, (j * mult), cos(angle) * ((j + 1) * mult), (i * mult), sin(angle) * (i * mult));
			plot_liney(ms, (j * mult), ((j + 1) * mult), (i * mult), (i * mult));
			j++;
		}
		i++;
	}
	return (i);
}

int		plot_liney(t_mlxs *ms, int x1, int x2, int y1, int y2) //based on https://en.wikipedia.org/wiki/Line_drawing_algorithm
{
	int	dx;
	int	dy;
	int	y;
	int	x;
	int	color;

	color = 0xFFFFFFFF;
	if (ms->color)
		color = ms->color;
	dx = x2 - x1;
	dy = y2 - y1;
	x = x1;
	while (x <= x2)
	{
		y = y1 + dy * (x - x1) / dx;
		put_pixel(ms->img1, y, x, color);
		x++;
	}
	ms->color = 0;
	return (x);
}


int		plot_line(t_mlxs *ms, int x1, int x2, int y1, int y2) //based on https://en.wikipedia.org/wiki/Line_drawing_algorithm
{
	int	dx;
	int	dy;
	int	y;
	int	x;
	int	color;
	
	color = 0xFFFFFFFF;
	if (ms->color)
		color = ms->color;
	dx = x2 - x1;
	dy = y2 - y1;
	x = x1;
	while (x <= x2)
	{
		y = y1 + dy * (x - x1) / dx;
		put_pixel(ms->img1, x, y, color);
		x++;
	}
	ms->color = 0;
	return (x);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*painter;

	painter = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)painter = color;
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

int	close_win(t_mlxs *ms)
{
	mlx_destroy_image(ms->mlx, ms->img1->img);
	mlx_destroy_window(ms->mlx, ms->win);
	mlx_destroy_display(ms->mlx);
	free(ms->mlx);
	free_close(ms, 0, ms->row);
	return (1);	
}

void	set_struct(t_mlxs *ms)
{
	ms->col = 1;
	ms->row = 0;
	ms->color = 0;
//	ms->mlx = NULL;
//	ms->win = NULL;
//	ms->xy = NULL;
//	ms->img1->img = NULL;
}

void	free_close(t_mlxs *ms, char *str, int rows)
{
	while(rows)
	{
		rows--;
		free(ms->xy[rows]);
	}
	if(ms->xy)
		free(ms->xy);
	if (!str)
		leave_program(0, 0, 0);
	leave_program(str, 2, 5);
}

int	parse_map(t_mlxs *ms, char *filename)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		leave_program("Error opening file\n", 2, 1);
	ms->xy = malloc(sizeof(t_coord *) * (ms->row));
	if (!ms->xy)
		free_close(ms, "Not enough memory to store map\n", 0);
	line = get_next_line(fd);
	while(i < ms->row)
	{
		fill_col(ms, line, i);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	free(line);
	return (ms->row);
}

int	fill_col(t_mlxs *ms, char *line, int row)
{
	int	col;

	col = 0;
	ms->xy[row] = malloc(sizeof(t_coord) * ms->col);
	if (!ms->xy[row])
		free_close(ms, "Not enough memory to fill map\n", row);
	while (col < ms->col)
	{
		while(*line == ' ')
			line++;
		ms->xy[row][col].z = ft_atoi(line);
		ms->xy[row][col].color = 0;
		while(*line != '\n' && *line != ' ' && *line != ',')
			line++;
		if (*line == ',')
		{
			ms->xy[row][col].color = ft_atoi_base(++line, 16);
			while(*line != '\n' && *line != ' ')
				line++;
		} 
		col++;
	}
	return(col);
}

int	validate_usage(int	argc, char **argv, t_mlxs *ms)
{
	int	fd;
	int	len;

	if (argc != 2)
		leave_program("Usage: <program name> <file.fdf>\n", 2, 1);
	len = ft_strlen(argv[1]);
	if (len < 5 || ft_strncmp(".fdf", &argv[1][len -4], 5))
		leave_program("Please input a valid <.fdf> file\n", 2, 2);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		leave_program("Error opening file\n", 2, 3);
	if (!count_map(fd, ms))
		leave_program("Can't parse this map\n", 2, 4);
	ft_printf("Map %s has %i rows and %i columns\n", argv[1], ms->row, ms->col);
	close(fd);
	return (1);
}

int	count_map(int fd, t_mlxs *ms)
{
	char	c;

	c = ' ';
	while (c == ' ')
		read(fd, &c, 1);
	while(read(fd, &c, 1))
	{
		if (c == ' ' && !ms->row) //removed validator
		{
			while (c == ' ')
				read(fd, &c, 1);
			if (c != '\n')
				ms->col++;
		}
		if (c == '\n' || c == 0)
		{
			ms->row++;
			while (read(fd, &c, 1) && (c == '\n' || c == 0))
				read(fd, &c, 1);
		}
	}
	if (ms->row)
		return (1);
	return (0);
}

void	leave_program(char *str, int fd, int return_code)
{
	if (return_code == 0)
		exit (0);
	ft_putstr_fd(str, fd);
	exit (return_code);
}
