/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:39:59 by maalexan          #+#    #+#             */
/*   Updated: 2023/02/08 21:58:17 by maalexan         ###   ########.fr       */
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
#  define N_PLU_K 65453
#  define N_MIN_K 65451
#  define ARW_U_K 65362
#  define ARW_D_K 65364
#  define ARW_L_K 65361
#  define ARW_R_K 65363
#  define O_KEY 111
#  define P_KEY 112
#  define K_KEY 107
#  define L_KEY 108
#  define R_KEY 114
#  define G_KEY 103
#  define B_KEY 98
#  define QUEST_K 47

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		color;
	int		endian;
}			t_img;

typedef struct	s_coord {
	int		x;
	int		y;
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
	t_coord	**cart;
	double	matrix[4][4];
	int		col;
	int		row;
	int		color;
	int		toggle;
	int		scale;
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
void	put_pixel(t_img *img, int x, int y);
void	high(t_mlxs *ms, t_line *l);
void	low(t_mlxs *ms, t_line *l);
void	printmap(t_mlxs *ms);
void	scale_matrix(t_mlxs *ms, int diag, int fill);

int		mouse_group(int keycode, int x, int y, t_mlxs *ms);
void	fad_toggle(t_mlxs *ms);
void	clear_img(t_img *img);
int		see_color(t_mlxs *ms, int color);
void	mult_matrix(int m1[4][4], int m2[4][4]);
void	apply_matrix(t_mlxs *ms, t_line *l);
void	printma(int	matrix[4][4]);
void	draw_line(t_mlxs *ms, t_coord ini, t_coord fin, t_line *l);

void	x_angle_matrix(t_mlxs *ms);

#endif