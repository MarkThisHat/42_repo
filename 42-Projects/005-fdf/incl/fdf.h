/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:39:59 by maalexan          #+#    #+#             */
/*   Updated: 2023/03/01 11:19:57 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# include "../libs/libft/incl/libft.h"
# include "/usr/local/include/mlx.h"
# include <fcntl.h>
# include <math.h>

#  define WIN_H 1080 // 2
#  define WIN_W 1920 // 2
#  define ESC_K 65307
#  define ARW_U_K 65362
#  define ARW_D_K 65364
#  define ARW_L_K 65361
#  define ARW_R_K 65363
#  define BCKSPC 65288
#  define P_KEY 112
#  define G_KEY 103
#  define B_KEY 98
#  define U_KEY 117
#  define J_KEY 106
#  define I_KEY 105
#  define K_KEY 107
#  define O_KEY 111
#  define L_KEY 108
#  define R_KEY 114
#  define Z_KEY 122
#  define X_KEY 120
#  define N_PLU_K 65453
#  define N_MIN_K 65451

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		color;
	int		endian;
}			t_img;

typedef struct	s_coord {
	double	xyz[3];
	int		z;
	int		color;
}			t_coord;

typedef struct	s_line {
	int		x0;
	int		x1;
	int		y0;
	int		y1;
	int		d;
	int		dx;
	int		dy;
	int		factor;
}		t_line;

typedef struct	s_mlxs {
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
	double	mapspot;
}			t_mlxs;

//fdf.c
void	set_struct(t_mlxs *ms);
void	draw_map(t_mlxs *ms);
void	draw_line(t_mlxs *ms, t_coord ini, t_coord fin, t_line *l);
void	mlx_setup(t_mlxs *ms);
//bresenham.c
void	put_pixel(t_img *img, int x, int y, int factor);
void	low_slope(t_mlxs *ms, t_line *l, int n);
void	high_slope(t_mlxs *ms, t_line *l, int n);
void 	put_line(t_mlxs *ms, t_line *l);
//management.c
int		validate_usage(int	argc, char **argv, t_mlxs *ms);
int		mouse_group(int keycode, int x, int y, t_mlxs *ms);
int		keypress(int keycode, t_mlxs *ms);
void	redraw_map(t_mlxs *ms);
//maptreat.c
int		parse_map(t_mlxs *ms, char *filename);
int		fill_col(t_mlxs *ms, char *line, int row);
int		count_col(int fd, t_mlxs *ms);
int		count_row(int fd, t_mlxs *ms);
void	coord_calibrate(t_mlxs *ms, t_coord *cart, int i, int j);
t_coord	**allocate_map(t_mlxs *ms);
//matrix.c
void	dot_product(t_coord *c, double m[4][4]);
void	angle_matrix(t_mlxs *ms, int axis, double angle);
void	rotation_matrix(double matrix[4][4], int axis, double angle);
void	crosswise_matrix(double matrix[4][4], double diag, double fill);
void	meld_matrix(t_mlxs *ms, double m1[4][4], double m2[4][4]);
//utils.c
int		invert_endian(int color);
int		close_win(t_mlxs *ms);
void	free_close(t_mlxs *ms, char *str, int rows);
void	leave_program(char *str, int fd, int return_code);
int		see_color(t_mlxs *ms, int color, int z);
//tempinfdf.c
void	position_img(t_mlxs *ms);
void	put_dot(t_mlxs *ms, double matrix[4][4]);
int		mouserelease(int keycode, int x, int y, t_mlxs *ms);
int		mousemove(int x, int y, t_mlxs *ms);
void	change_height(t_mlxs *ms, int change);

//bonus
int		keybonus(int keycode, t_mlxs *ms);
void	fad_toggle(t_mlxs *ms);
void	clear_img(t_img *img);
void	bonus_roll(t_mlxs *ms, int axis, double amount);
void	bonus_scale(t_mlxs *ms, int negative);
void	reset_placement(t_mlxs *ms);
//mousebonus
int		my_mouse_hook(int button, int x, int y, t_mlxs *ms);
int		my_loop_function(t_mlxs *ms);
//gpt
void	keep_bound(t_line *l);

//colors
int		add_factor(int color, int factor);
int		put_colors(int color, int factor);
void	add_color(int *color, int *dye, int bitshift);
int	adjust_ambit(t_mlxs *ms, int height, int width);




#endif

/****\
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
void	put_pixel(t_img *img, int x, int y);
void	high(t_mlxs *ms, t_line *l);
void	low(t_mlxs *ms, t_line *l);
void	printmap(t_mlxs *ms);
void	scale_matrix(t_mlxs *ms, int diag, int fill);

int		mouse_group(int keycode, int x, int y, t_mlxs *ms);
void	fad_toggle(t_mlxs *ms);
void	clear_img(t_img *img);
int		see_color(t_mlxs *ms, int color);
void	draw_line(t_mlxs *ms, t_coord ini, t_coord fin, t_line *l);
void	dot_product(t_coord *c, double m[4][4]);
void	angle_matrix(t_mlxs *ms, int axis, double angle);
void	rotation_matrix(double matrix[4][4], int axis, double angle);
void	crosswise_matrix(double matrix[4][4], double diag, double fill);
void	meld_matrix(t_mlxs *ms, double m1[4][4], double m2[4][4]);
void	calibration(t_mlxs *ms, t_coord *cart, int i, int j);


void	x_angle_matrix(t_mlxs *ms);
\*****/