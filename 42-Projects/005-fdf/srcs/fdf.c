/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:37:28 by maalexan          #+#    #+#             */
/*   Updated: 2023/01/25 13:23:07 by maalexan         ###   ########.fr       */
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

typedef struct	s_mlxs {
	void	*mlx;
	void	*win;
	t_img	*img1;
	t_img	*img2;
	int		col;
	int		row;
	int		x;
	int		y;
	int		z;
	int		color;
}			t_mlxs;
*/

int	main(int argc, char **argv)
{
	t_mlxs	main_struct;

	if (validate_usage(argc, argv, &main_struct))
		leave_program(0, 0, 0);
}

int	validate_usage(int	argc, char **argv, t_mlxs *ms)
{
	int	fd;
	int	len;

	if (argc != 2)
		leave_program("Usage: <program name> <file.fdf>\n", 2, 1);
	len = ft_strlen(argv[1]);
	if (len < 5 || ft_strncmp(".fdf", &argv[1][len -4], 5))
		leave_program("Please input a valid <.fdf> file\n", 2, 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		leave_program("Error opening file\n", 2, 1);
	if (!count_map(fd, ms))
		leave_program("Can't parse this map\n", 2, 1);
	ft_printf("Map %s has %i rows and %i columns\n", argv[1], ms->row, ms->col);
	close(fd);
	return (1);
}

int	count_map(int fd, t_mlxs *ms)
{
	char	c;
	char	col_val;

	c = ' ';
	while (c == ' ')
		read(fd, &c, 1);
	ms->row = 0;
	ms->col = 1;
	col_val = 1;
	while(read(fd, &c, 1))
	{
		if (c == ' ' && col_val)
		{
			while (c == ' ')
				read(fd, &c, 1);
			if (c != '\n')
				ms->col++;
		}
		if (c == '\n' || c == 0)
		{
			ms->row++;
			col_val = 0;
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
