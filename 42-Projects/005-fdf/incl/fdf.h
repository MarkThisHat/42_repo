/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:39:59 by maalexan          #+#    #+#             */
/*   Updated: 2023/02/03 18:33:17 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# include "../libs/libft/incl/libft.h"
# include "/usr/local/include/mlx.h"
# include <fcntl.h>
# include <math.h>

#  define WIN_H 1080 / 2
#  define WIN_W 1920 / 2
#  define ESC_K 65307

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		color;
	int		endian;
}			t_img;

typedef struct	s_coord {
	int		z;
	int		color;
}			t_coord;

typedef struct	s_line {
	int		x0;
	int		x1;
	int		y0;
	int		y1;
	int		dx;
	int		dy;
	double	angl;
}		t_line;

typedef struct	s_mlxs {
	void	*mlx;
	void	*win;
	t_img	*img1;
	t_img	*img2;
	t_img	**fad;
	t_coord	**xy;
	int		col;
	int		row;
	int		color;
	int		focus;
	int		scale;
	int		toggle;
	double	angle;
}			t_mlxs;

void	mlx_setup(t_mlxs *ms);
int		validate_usage(int	argc, char **argv, t_mlxs *ms);
int		count_col(int fd, t_mlxs *ms);
int		count_row(int fd, t_mlxs *ms);
void	set_struct(t_mlxs *ms);
int		parse_map(t_mlxs *ms, char *filename);
int		fill_col(t_mlxs *ms, char *line, int row);
int		keypress(int keycode, t_mlxs *ms);
int		close_win(t_mlxs *ms);
void	free_close(t_mlxs *ms, char *str, int rows);
void	leave_program(char *str, int fd, int return_code);
int 	invert_endian(int color);
int		set_points(t_line *l);
void	put_line(t_mlxs *ms, t_line *l);
void	draw_map(t_mlxs *ms);
void	draw_col(t_mlxs *ms, int i, int j, t_line *l);
void	draw_row(t_mlxs *ms, int i, int j, t_line *l);
void	put_pixel(t_img *img, int x, int y);
int	isoy(t_mlxs *ms, int y, int z);
int	isox(t_mlxs *ms, int x, int z);
void	iso_zero(t_line *l, int x, int y, int z);
void	iso_one(t_line *l, int x, int y, int z);
void	high(t_mlxs *ms, t_line *l);
void	low(t_mlxs *ms, t_line *l);
void	printmap(t_mlxs *ms);

#endif