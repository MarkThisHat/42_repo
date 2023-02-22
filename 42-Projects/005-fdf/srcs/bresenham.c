/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:29:47 by maalexan          #+#    #+#             */
/*   Updated: 2023/02/22 16:51:38 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	put_pixel(t_img *img, int x, int y)
{
	char			*painter;
	unsigned int	color;
	int				target;

	target = (x * img->line_length) + (y * (img->bits_per_pixel / 8));
	if (target < 0 || target > (WIN_H * img->line_length))
		return ;
	if (img->endian)
		img->color = invert_endian(img->color);
	painter = img->addr + target;
	color = img->color - (img->color << 24);
	color += 0xFF000000;
	*(unsigned int*)painter = color;
}

void	low(t_mlxs *ms, t_line *l)
{
	int n;
	int	d;
	int	x;
	int	y;
	
	l->dx = l->x1 - l->x0;
	l->dy = l->y1 - l->y0;
	n = 1;
	if (l->dy < 0)
	{
		n = -1;
		l->dy *= -1;
	}
	d = (2 * l->dy) - l->dx;
	y = l->y0;
	x = l->x0;
	while (x < l->x1)
	{
		put_pixel(*ms->fad, x, y);
		if (d > 0)
		{
			y = y + n;
			d = d + (2 * (l->dy - l->dx));
        }
		else
			d = d + 2 * l->dy;
		x++;
	}
}

void	high(t_mlxs *ms, t_line *l)
{
	int	n;
	int d;
	int x;
	int y;

	l->dx = l->x1 - l->x0;
	l->dy = l->y1 - l->y0;
	n = 1;
	if (l->dx < 0)
	{
		n = -1;
		l->dx *= -1;
	}
	d = (2 * l->dx) - l->dy;
	x = l->x0;
	y = l->y0;
	while (y < l->y1)
	{
		put_pixel(*ms->fad, x, y);
		if (d > 0)
		{
			x = x + n;
			d = d + (2 * (l->dx - l->dy));
        }
		else
			d = d + 2 * l->dx;
		y++;
	}
}


void put_line(t_mlxs *ms, t_line *l)
{
    t_line p;

    p.x1 = l->x0;
    p.y1 = l->y0;
    p.x0 = l->x1;
    p.y0 = l->y1;
    if (abs(l->y1 - l->y0) < abs(l->x1 - l->x0))
	{
        if (l->x0 > l->x1)
            low(ms, &p);//x1, y1, x0, y0
        else
            low(ms, l);//x0, y0, x1, y1
    }
    else
    {
        if (l->y0 > l->y1)
            high(ms, &p);//x1, y1, x0, y0
        else
            high(ms, l);//x0, y0, x1, y1
    }
}
