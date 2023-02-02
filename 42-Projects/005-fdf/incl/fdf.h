/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:39:59 by maalexan          #+#    #+#             */
/*   Updated: 2023/02/01 21:36:36 by maalexan         ###   ########.fr       */
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

typedef struct	s_vect {
	double	x;
	double	y;
	double	z;
}				t_vect;

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

void	mlx_setup(t_mlxs *ms);
int		validate_usage(int	argc, char **argv, t_mlxs *ms);
int		count_map(int fd, t_mlxs *ms);
void	set_struct(t_mlxs *ms);
int		parse_map(t_mlxs *ms, char *filename);
int		fill_col(t_mlxs *ms, char *line, int row);
int		keypress(int keycode, t_mlxs *ms);
int		close_win(t_mlxs *ms);
void	free_close(t_mlxs *ms, char *str, int rows);
void	leave_program(char *str, int fd, int return_code);
int 	invert_endian(int color);
void	swap(double *a, double *b);
double	get_fract(double n);
void	put_line(t_mlxs *ms, t_vect p1, t_vect p2);
void	plot_coords(t_mlxs *ms, t_vect p1, t_vect p2);
void	draw_slope(t_mlxs *ms, double x, double y);
void	draw_map(t_mlxs *ms);
void	put_pixel(t_img *img, int x, int y, double smoother);

#endif