/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:48:41 by maalexan          #+#    #+#             */
/*   Updated: 2023/03/07 12:29:27 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	leave_program(char *str, int fd, int return_code)
{
	if (return_code == 0)
		exit (0);
	ft_putstr_fd(str, fd);
	exit (return_code);
}

void	set_struct(t_mlxs *ms, t_img *img1, t_img *img2)
{
	*ms = (t_mlxs) {0};
	*img1 = (t_img) {0};
	*img2 = (t_img) {0};
	ms->color = 0xFFFFFFFF;
	ms->toggle = 42;
	ms->fad = &ms->img1;
	ms->height_adj =  WIN_H / 6;
	ms->width_adj = WIN_W / 2;
	crosswise_matrix(ms->matrix, 1, 0);
}

int		validate_usage(int	argc, char **argv, t_mlxs *ms)
{
	int	fd;
	int	len;

	if (argc != 2)
		leave_program("Usage: <program name> <file.fdf>\n", 2, 1);
	len = ft_strlen(argv[1]);
	if (len < 5 || ft_strncmp(".fdf", &argv[1][len - 4], 5))
		leave_program("Please input a valid <.fdf> file\n", 2, 2);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		leave_program("Error opening file\n", 2, 3);
	if (!count_col(fd, ms))
		leave_program("Can't parse this map\n", 2, 4);
	ft_printf("Map %s has %i rows and %i columns\n", argv[1], ms->row, ms->col);//REMOVE
	close(fd);
	return (1);
}

void	set_matrixes(t_mlxs *ms, int average)
{
	double	matrix[4][4];

	crosswise_matrix(matrix, 1, 0);
	meld_matrix(ms, ms->matrix, matrix);
	crosswise_matrix(matrix, ms->mapspot / 2, 0);
	matrix[2][2] = ms->scale;
	matrix[3][3] = 1;
	if (ms->scale == 1 && average < 100)
		matrix[2][2] = 0.1;
	if ((ms->higher - ms->lower) >= (ms->row + ms->col))
		matrix[2][2] = average;
	meld_matrix(ms, ms->matrix, matrix);
	angle_matrix(ms, 2, M_PI * 0.25);
	angle_matrix(ms, 0, M_PI * 0.304);
	put_dot(ms, ms->matrix);
}

void	coord_calibrate(t_mlxs *ms, t_coord *cart, int i, int j)
{
	cart->xyz[0] = i;
	cart->xyz[1] = j;
	cart->xyz[2] = cart->z;
	if (ms->higher < cart->z)
		ms->higher = cart->z;
	if (ms->lower > cart->z)
		ms->lower = cart->z;
}
