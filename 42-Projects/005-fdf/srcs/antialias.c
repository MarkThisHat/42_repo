/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialias.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:29:47 by maalexan          #+#    #+#             */
/*   Updated: 2023/02/01 20:48:29 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	put_line(t_mlxs *ms, t_vect p1, t_vect p2)
{
	double	dx;
	double	dy;

	if (fabs(p1.y - p2.y) > fabs(p1.x - p2.x))
		ms->steep = 1;
	else
		ms->steep = 0;
	if (ms->steep)
	{
		swap(&p1.x, &p1.y);
		swap(&p2.x, &p2.y);
	}
	if (p2.x < p1.x)
	{
		swap(&p1.x, &p2.x);
		swap(&p1.y, &p2.y);
	}
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	if (dx == 0)
		ms->gradient = 1;
	else
		ms->gradient = dy / dx;
	plot_coords(ms, p1, p2);
}

void	plot_coords(t_mlxs *ms, t_vect p1, t_vect p2)
{
	while (p1.x <= p2.x)
	{
		if (ms->steep)
			draw_slope(ms, p1.y, p1.x);
		else
			draw_slope(ms, p1.x, p1.y);
		p1.y += ms->gradient;
		p1.x++;
	}
}

void	draw_slope(t_mlxs *ms, double x, double y)
{
	t_img	*img;

	if (!ms->toggle)
		img = ms->img1;
	else
		img = ms->img2;
	if (ms->gradient >= 0)
	{
		put_pixel(img, floor(x), y, 1 - get_fract(y));
		put_pixel(img, floor(x) + 1, y, get_fract(y));
	}
	else if (ms->gradient < 0)
	{
		put_pixel(img, floor(x), y, 1 - get_fract(y));
		put_pixel(img, floor(x) - 1, y, get_fract(y));
	}
}

void	put_pixel(t_img *img, int x, int y, double smoother)
{
	char			*painter;
	unsigned int	alpha;
	int				color;
	int				target;

	if (!smoother)
		return ;
	target = y * img->line_length + x * (img->bits_per_pixel / 8);
	if (target < 0 || target > WIN_H * WIN_W)
		return ;
	if (img->endian)
		img->color = invert_endian(img->color);
	alpha = img->color;
	alpha = alpha >> 24;
	alpha = alpha * smoother;
	color = (alpha << 24) + (img->color - (img->color & 0xFF000000));
	painter = img->addr + target;
	*(unsigned int*)painter = color;
}
