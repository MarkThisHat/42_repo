/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptreat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:51:53 by maalexan          #+#    #+#             */
/*   Updated: 2023/02/22 17:37:04 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

int	parse_map(t_mlxs *ms, char *filename)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		leave_program("Error opening file\n", 2, 1);
	ms->cart = malloc(sizeof(t_coord *) * (ms->row));
	if (!ms->cart)
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
	ms->cart[row] = malloc(sizeof(t_coord) * ms->col);
	if (!ms->cart[row])
		free_close(ms, "Not enough memory to fill map\n", row);
	while (col < ms->col)
	{
		while(*line == ' ')
			line++;
		ms->cart[row][col].z = ft_atoi(line);
		coord_calibrate(ms, &ms->cart[row][col], row, col);
		ms->cart[row][col].color = 0;
		while(*line != '\n' && *line != ' ' && *line != ',')
			line++;
		if (*line == ',')
		{
			ms->cart[row][col].color = ft_atoi_base(++line, 16);
			while(*line != '\n' && *line != ' ')
				line++;
		} 
		col++;
	}
	return(col);
}

int		count_col(int fd, t_mlxs *ms)
{
	char	c;

	c = ' ';
	while (c == ' ' && read(fd, &c, 1));
	while(read(fd, &c, 1))
	{
		if (c == ' ')
		{
			while (c == ' ' && read(fd, &c, 1));
			if (c != '\n')
				ms->col++;
		}
		if (c == '\n')
		{
			ms->col++;
			return (count_row(fd, ms));
		}
	}
	return (0);
}

int		count_row(int fd, t_mlxs *ms)
{
	char 	c;
	int		val;

	if (!ms->col)
		return (0);
	ms->row++;
	val = 1;
	while(read(fd, &c, 1))
	{
		if (val && c != '\n')
		{
			ms->row++;
			val = 0;
		}
		if (c == '\n')
			val = 1;
	}
	if (ms->row < 3 && c != '\n')
		return (0);
	return (1);
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
	//dot_product(cart, ms->matrix);
}
