/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:29:47 by maalexan          #+#    #+#             */
/*   Updated: 2023/03/10 14:35:09 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	low_slope(t_mlxs *ms, t_line *l, int n)
{
	int	x;
	int	y;

	l->dx = l->x1 - l->x0;
	l->dy = l->y1 - l->y0;
	if (l->dy < 0)
	{
		n = -1;
		l->dy *= -1;
	}
	l->d = (2 * l->dy) - l->dx;
	y = l->y0;
	x = l->x0;
	while (x < l->x1)
	{
		put_pixel(*ms->fad, x, y, l->factor);
		if (l->d > 0)
		{
			y = y + n;
			l->d = l->d + (2 * (l->dy - l->dx));
		}
		else
			l->d = l->d + 2 * l->dy;
		x++;
	}
}

void	high_slope(t_mlxs *ms, t_line *l, int n)
{
	int	x;
	int	y;

	l->dx = l->x1 - l->x0;
	l->dy = l->y1 - l->y0;
	if (l->dx < 0)
	{
		n = -1;
		l->dx *= -1;
	}
	l->d = (2 * l->dx) - l->dy;
	x = l->x0;
	y = l->y0;
	while (y < l->y1)
	{
		put_pixel(*ms->fad, x, y, l->factor);
		if (l->d > 0)
		{
			x = x + n;
			l->d = l->d + (2 * (l->dx - l->dy));
		}
		else
			l->d = l->d + 2 * l->dx;
		y++;
	}
}

void	keep_bound(t_line *l)
{
	if (l->x0 < 0)
		l->x0 = 0;
	if (l->x0 >= WIN_W)
		l->x0 = WIN_W - 1;
	if (l->y0 < 0)
		l->y0 = 0;
	if (l->y0 >= WIN_H)
		l->y0 = WIN_H - 1;
	if (l->x1 < 0)
		l->x1 = 0;
	if (l->x1 >= WIN_W)
		l->x1 = WIN_W - 1;
	if (l->y1 < 0)
		l->y1 = 0;
	if (l->y1 >= WIN_H)
		l->y1 = WIN_H - 1;
}

void	put_line(t_mlxs *ms, t_line *l)
{
	t_line	p;

	keep_bound(l);
	p.x1 = l->x0;
	p.y1 = l->y0;
	p.x0 = l->x1;
	p.y0 = l->y1;
	p.factor = l->factor;
	if (l->factor)
		(*ms->fad)->color = ms->dye;
	if (abs(l->y1 - l->y0) < abs(l->x1 - l->x0))
	{
		if (l->x0 > l->x1)
			low_slope(ms, &p, 1);
		else
			low_slope(ms, l, 1);
	}
	else
	{
		if (l->y0 > l->y1)
			high_slope(ms, &p, 1);
		else
			high_slope(ms, l, 1);
	}
}
