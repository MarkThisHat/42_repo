/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:39:59 by maalexan          #+#    #+#             */
/*   Updated: 2023/03/10 16:16:36 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libs/libft/incl/libft.h"
# include "/usr/local/include/mlx.h"
# include <fcntl.h>
# include <math.h>

# define WIN_H 1080
# define WIN_W 1920
# define ESC_K 65307

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		color;
	int		endian;
}			t_img;

typedef struct s_coord {
	double	xyz[3];
	int		z;
	int		color;
}			t_coord;

typedef struct s_line {
	int		x0;
	int		x1;
	int		y0;
	int		y1;
	int		d;
	int		dx;
	int		dy;
	int		factor;
}		t_line;

typedef struct s_mlxs {
	void	*mlx;
	void	*win;
	t_img	*img1;
	t_img	*img2;
	t_img	**fad;
	t_coord	**cart;
	double	matrix[4][4];
	int		col;
	int		row;
	int		color;
	int		dye;
	int		toggle;
	int		scale;
	int		higher;
	int		lower;
	int		height_adj;
	int		width_adj;
	int		remodel[6];
	double	mapspot;
}			t_mlxs;

void	mlx_setup(t_mlxs *ms);
int		close_win(t_mlxs *ms);
void	free_close(t_mlxs *ms, char *str, int rows);
int		keypress(int keycode, t_mlxs *ms);
void	low_slope(t_mlxs *ms, t_line *l, int n);
void	high_slope(t_mlxs *ms, t_line *l, int n);
void	keep_bound(t_line *l);
void	put_line(t_mlxs *ms, t_line *l);
void	leave_program(char *str, int fd, int return_code);
void	set_struct(t_mlxs *ms, t_img *img1, t_img *img2);
void	set_matrixes(t_mlxs *ms, int average);
int		validate_usage(int argc, char **argv, t_mlxs *ms);
void	coord_calibrate(t_mlxs *ms, t_coord *cart, int i, int j);
int		count_col(int fd, t_mlxs *ms);
int		count_row(int fd, t_mlxs *ms);
int		parse_map(t_mlxs *ms, char *filename);
t_coord	**allocate_map(t_mlxs *ms);
int		fill_col(t_mlxs *ms, char *line, int row);
void	position_img(t_mlxs *ms);
void	put_pixel(t_img *img, int x, int y, int factor);
void	clear_img(t_img *img);
void	draw_map(t_mlxs *ms);
void	draw_line(t_mlxs *ms, t_coord ini, t_coord fin, t_line *l);
int		add_factor(int color, int factor);
int		put_colors(int color, int factor);
void	add_color(int *color, int *dye, int bitshift);
int		invert_endian(int color);
int		see_color(t_mlxs *ms, int color, int z);
void	angle_matrix(t_mlxs *ms, int axis, double angle);
void	rotation_matrix(double matrix[4][4], int axis, double angle);
void	crosswise_matrix(double matrix[4][4], double diag, double fill);
void	copy_matrix(double src[4][4], double dest[4][4]);
void	meld_matrix(t_mlxs *ms, double m1[4][4], double m2[4][4]);
void	dot_product(t_coord *c, double m[4][4]);
void	put_dot(t_mlxs *ms, double matrix[4][4]);
void	translate_point(t_mlxs *ms, int x, int y, int z);

#endif
