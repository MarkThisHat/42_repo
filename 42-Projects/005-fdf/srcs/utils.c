/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:49:16 by maalexan          #+#    #+#             */
/*   Updated: 2023/02/01 20:50:05 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

int invert_endian(int color)
{
	int alpha;
	int red;
	int green;
	int blue;

	blue = color & 0xFF000000;
	green = color & 0x00FF0000;
	red = color & 0x0000FF00;
	alpha = color & 0x000000FF;
	color = (alpha << 24) + (red << 8) + (green >> 8) + (blue >> 24);
	return (color);
}

int		close_win(t_mlxs *ms)
{
	if (ms->toggle == 42)
		mlx_destroy_image(ms->mlx, (*ms->fad)->img);
	else
	{
		mlx_destroy_image(ms->mlx, ms->img1->img);
		mlx_destroy_image(ms->mlx, ms->img2->img);
	}
	mlx_destroy_window(ms->mlx, ms->win);
	mlx_destroy_display(ms->mlx);
	free(ms->mlx);
	free_close(ms, 0, ms->row);
	return (1);	
}

void	free_close(t_mlxs *ms, char *str, int rows)
{
	while(rows)
	{
		rows--;
		free(ms->cart[rows]);
	}
	if(ms->cart)
		free(ms->cart);
	if (!str)
		leave_program(0, 0, 0);
	leave_program(str, 2, 5);
}

void	leave_program(char *str, int fd, int return_code)
{
	if (return_code == 0)
		exit (0);
	ft_putstr_fd(str, fd);
	exit (return_code);
}
