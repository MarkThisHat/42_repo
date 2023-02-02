/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptreat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:51:53 by maalexan          #+#    #+#             */
/*   Updated: 2023/02/01 20:52:15 by maalexan         ###   ########.fr       */
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
