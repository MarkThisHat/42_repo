/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:50:18 by maalexan          #+#    #+#             */
/*   Updated: 2023/02/04 20:37:44 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

int		validate_usage(int	argc, char **argv, t_mlxs *ms)
{
	int	fd;
	int	len;

	if (argc != 2)
		leave_program("Usage: <program name> <file.fdf>\n", 2, 1);
	len = ft_strlen(argv[1]);
	if (len < 5 || ft_strncmp(".fdf", &argv[1][len -4], 5))
		leave_program("Please input a valid <.fdf> file\n", 2, 2);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		leave_program("Error opening file\n", 2, 3);
	if (!count_map(fd, ms))
		leave_program("Can't parse this map\n", 2, 4);
	ft_printf("Map %s has %i rows and %i columns\n", argv[1], ms->row, ms->col);
	close(fd);
	return (1);
}

int		count_map(int fd, t_mlxs *ms)
{
	char	c;

	c = ' ';
	while (c == ' ' && read(fd, &c, 1));
	while(read(fd, &c, 1))
	{
		if (c == ' ' && !ms->row) //removed validator
		{
			while (c == ' ' && read(fd, &c, 1));
			if (c != '\n')
				ms->col++;
		}
		if (c == '\n' || c == 0)
		{
			ms->row++;
			while (read(fd, &c, 1) && (c == '\n' || c == 0));
		}
	}
	if (ms->row)
		return (1);
	return (0);
}

void	set_struct(t_mlxs *ms)
{
	ms->col = 1;
	ms->row = 0;
	ms->color = 0;
	ms->toggle = 0;
//	ms->mlx = NULL;
//	ms->win = NULL;
//	ms->xy = NULL;
//	ms->img1->img = NULL;
}