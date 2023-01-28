/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:39:59 by maalexan          #+#    #+#             */
/*   Updated: 2023/01/27 22:04:03 by maalexan         ###   ########.fr       */
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
	int		endian;
}			t_img;

typedef struct	s_coord {
	int		z;
	int		color;
}			t_coord;

typedef struct	s_mlxs {
	void	*mlx;
	void	*win;
	t_img	*img1;
	t_img	*img2;
	t_coord	**xy;
	int		col;
	int		row;
	int		color;
}			t_mlxs;

void	set_struct(t_mlxs *ms);
int		count_map(int fd, t_mlxs *ms);
int		parse_map(t_mlxs *ms, char *filename);
int		fill_col(t_mlxs *ms, char *line, int row);
int		validate_usage(int argc, char **argv, t_mlxs *ms);
void	mlx_setup(t_mlxs *ms);
int		keypress(int keycode, t_mlxs *ms);
void	put_pixel(t_img *img, int x, int y, int color);
int		plot_line(t_mlxs *ms, int x1, int x2, int y1, int y2);
void	free_close(t_mlxs *ms, char *str, int rows);
void	leave_program(char *str, int fd, int return_code);

#endif