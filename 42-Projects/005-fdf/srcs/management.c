/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:48:41 by maalexan          #+#    #+#             */
/*   Updated: 2023/02/01 20:49:01 by maalexan         ###   ########.fr       */
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
	if (!count_col(fd, ms))
		leave_program("Can't parse this map\n", 2, 4);
	ft_printf("Map %s has %i rows and %i columns\n", argv[1], ms->row, ms->col);
	close(fd);
	return (1);
}

int		keypress(int keycode, t_mlxs *ms)
{
	if (keycode == ESC_K)
		close_win(ms);
	//below here is bonus
	if (keycode == 112)
		ms->angle += 0.1;
	if (keycode == 111)
		ms->angle -= 0.1;
	mlx_clear_window(ms->mlx, ms->win);
	fad_toggle(ms);
	draw_map(ms);
	mlx_put_image_to_window(ms->mlx, ms->win, (*ms->fad)->img, 0, 0);
	ft_printf("%i\n", keycode);
	return (keycode);
}

void	fad_toggle(t_mlxs *ms)
{
	if (ms->toggle == 42)
	{
		ms->fad = &ms->img2;
		(*ms->fad)->img = mlx_new_image(ms->mlx, WIN_W, WIN_H);
		(*ms->fad)->addr = mlx_get_data_addr((*ms->fad)->img, &(*ms->fad)->bits_per_pixel, &(*ms->fad)->line_length, &(*ms->fad)->endian);
		ms->toggle = 0;
		return ;
	}
	if (!ms->toggle)
	{
		ms->fad = &ms->img1;
		ms->toggle = 1;
	}
	else
	{
		ms->fad = &ms->img2;
		ms->toggle = 0;
	}
}

