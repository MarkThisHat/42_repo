/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dotconnect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:29:47 by maalexan          #+#    #+#             */
/*   Updated: 2023/02/04 21:28:33 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	put_pixel(t_img *img, int x, int y)
{
	char			*painter;
	unsigned int	color;
	int				target;

	if (x > WIN_H || y > WIN_W)
		return ;
	target = (x * img->line_length) + (y * (img->bits_per_pixel / 8));
	//ft_printf("img->line_length %i img->bits_per_pixel %i x %i y %i WIN_H * WIN_W %i target %i\n",img->line_length, img->bits_per_pixel, x, y, WIN_H * WIN_W, target);
	if (target < 0) //|| target > WIN_H * img->line_length)
		return ;
	if (img->endian)
		img->color = invert_endian(img->color);
	painter = img->addr + target;
	color = img->color - (img->color << 24);
	//ft_printf("was %#x is %#x\n", img->color, color);
	color += 0xFF000000;
	*(unsigned int*)painter = color;
}

void put_line(t_mlxs *ms, t_line *l)
{
    int err;
	int	e2;

	err = set_points(l);
	while(l->x0 <= l->x1 && l->y0 <= l->y1) 
	{
		put_pixel(ms->img1, l->x0, l->y0);
		e2 = 2 * err;
		if (e2 >= l->dy) 
		{
			err += l->dy;
			l->x0 += l->sx;
        }
        if (e2 <= l->dx)
		{
			err += l->dx;
			l->y0 += l->sy;
        }
    }
}

int	set_points(t_line *l)
{
	l->dx = abs(l->x1 - l->x0);
	l->dy = -abs(l->y1 - l->y0);
	if (l->x0 < l->x1)
		l->sx = 1;
	else
		l->sx = -1;
	if (l->y0 < l->y1)
		l->sy = 1;
	else
		l->sy = -1;
	return (l->dx + l->dy);
}


/*

void put_line(t_mlxs *ms, t_line *l)
{
    int err;
	int	e2;

	err = set_points(l);
	while(x0 <= x1 && y0 <= y1) 
	{
		put_pixel(ms->img1, y0, x0);
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

int	set_points(t_line *l)
{
	dx = abs(x1 - x0);
	dy = -abs(y1 - y0);
	if (x0 < x1)
		sx = 1;
	else
		sx = -1;
	if (y0 < y1)
		sy = 1;
	else
		sy = -1;
	return (dx + dy);
}

*/