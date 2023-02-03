/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialias.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:29:47 by maalexan          #+#    #+#             */
/*   Updated: 2023/02/01 21:50:40 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	put_pixel(t_img *img, int x, int y)
{
	char			*painter;
	int				color;
	int				target;

	target = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	ft_printf("img->line_length %i img->bits_per_pixel %i x %i y %i WIN_H * WIN_W %i target %i\n",img->line_length, img->bits_per_pixel, x, y, WIN_H * WIN_W, target);
	if (target < 0)// || target > WIN_H * WIN_W)
		return ;
	if (img->endian)
		img->color = invert_endian(img->color);
	painter = img->addr + target;
	color = img->color & 0xFF000000;
	*(unsigned int*)painter = color;
}


void put_line(t_mlxs *ms, int x0, int y0, int x1, int y1)
{
    int dx;
    int dy;
    int err;
	int	e2;
	int	sx;
	int	sy;

	dx = abs(x1 - x0);
	dy = -abs(y1 -y0);
	err = dx + dy;
	if (x0 < x1)
		sx = 1;
	else
		sx = -1;
	if (y0 < y1)
		sy = 1;
	else
		sy = -1;
	while(x0 <= x1 && y0 <= y1) 
	{
		put_pixel(ms->img1, x0, y0);
		e2 = 2 * err;
		if (e2 >= dy) 
		{
			err += dy;
			x0 += sx;
        }
        if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
        }
    }
}
