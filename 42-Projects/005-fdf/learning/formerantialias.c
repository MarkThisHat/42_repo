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
/*
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
	ft_printf("got to putline\n");
	plot_coords(ms, p1, p2);
}*/

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
	ft_printf("got to plot_coords\n");
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
	ft_printf("got to draw_slope\n");
}


void	put_pixel(t_img *img, int x, int y, double smoother)
{
	char			*painter;
	unsigned int	alpha;
	int				color;
	int				target;

	if (!smoother)
		return ;
	ft_printf("got to put pixel b4if\n");
	target = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	ft_printf("img->line_length %i img->bits_per_pixel %i x %i y %i WIN_H * WIN_W %i target %i\n",img->line_length, img->bits_per_pixel, x, y, WIN_H * WIN_W, target);
	if (target < 0)// || target > WIN_H * WIN_W)
		return ;
	if (img->endian)
		img->color = invert_endian(img->color);
	alpha = img->color;
	alpha = alpha >> 24;
	alpha = alpha * smoother;
	color = (alpha << 24) + (img->color - (img->color & 0xFF000000));
	painter = img->addr + target;
	*(unsigned int*)painter = color;
	ft_printf("got to put pixel afterif\n");
}


void best_put_line(t_mlxs *ms, int x0, int y0, int x1, int y1)
{
    int dx =  abs(x1-x0), sx = x0<x1 ? 1 : -1;
    int dy = -abs(y1-y0), sy = y0<y1 ? 1 : -1;
    int err = dx+dy, e2;                                  /* error value e_xy */

    while(42) {                                                        /* loop */
        put_pixel(ms->img1, x0, y0, 1);
        e2 = 2*err;
        if (e2 >= dy) {                                       /* e_xy+e_x > 0 */
            if (x0 == x1) break;
            err += dy; x0 += sx;
        }
        if (e2 <= dx) {                                       /* e_xy+e_y < 0 */
            if (y0 == y1) break;
            err += dx; y0 += sy;
        }
    }
}
/*
void	put_line(t_mlxs *ms, t_vect p1, t_vect p2)
{
	int	dx;
	int	dy;
	int	y;
	int delta;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	delta = 2 * dy - dx;
	y = p1.y;

	while (p1.x <= p2.x)
	{
		put_pixel(ms->img1, p1.x, y, 1);
		if (delta > 0)
		{
			y = y + 1;
			delta = (delta - 2*dx);
		}
		delta = delta + (2 * dy);
		p1.x++;
	}
}

double floor_round(double x)
{
	return (floor(x + 0.5));
}

double fpart(double x)
{
	return (x - floor_round(x));
}

double rfpart(double x)
{
	return (1 - fpart(x));
}

void	wu_xiao(t_mlxs *ms, double x0, double x1, double y0, double y1)
{
	ft_printf("got to wuxiao\n");
	double	dx;
	double	dy;

	if (fabs(y1 - y0) > fabs(x1 - x0))
		ms->steep = 1;
	if (ms->steep)
	{
		swap(&x0, &y0);
		swap(&x1, &y1);
	}
	if (x0 > x1)
	{
		swap(&x0, &x1);
		swap(&y0, &y1);
	}
	dx = x1 - x0;
	dy = y1 - y0;
	if (!dx)
		ms->gradient = 1;
	else
		ms->gradient = dy / dx;
	//first endpoint?
	double xend = floor_round(x0);
	double yend = y0 + ms->gradient * (xend - x0);
	double xgap = rfpart(x0 + 0.5);
	double xpxl1 = xend;
	double ypxl1 = floor(yend);
	if (ms->steep)
	{
		put_pixel(ms->img1, ypxl1, xpxl1, rfpart(yend) * xgap);
		put_pixel(ms->img1, ypxl1 + 1, xpxl1, fpart(yend) * xgap);
	}
	else
	{
		put_pixel(ms->img1, xpxl1, ypxl1, rfpart(yend) * xgap);
		put_pixel(ms->img1, xpxl1, ypxl1 + 1, fpart(yend) * xgap);
	}
	double intery = yend + ms->gradient; //tf is an y-intersection for main loop?
	//second endpoint?
	xend = floor_round(x1);
	yend = y1 + ms->gradient * (xend - x1);
	xgap = fpart(x1 + 0.5);
	int xpxl2 = xend; //main loop?
	int ypxl2 = floor(yend);
	if(ms->steep)
	{
		put_pixel(ms->img1, ypxl2, xpxl2, rfpart(yend) * xgap);
		put_pixel(ms->img1, ypxl2 + 1, xpxl2,  fpart(yend) * xgap);
	}
	else
	{
		put_pixel(ms->img1, xpxl2, ypxl2, rfpart(yend) * xgap);
		put_pixel(ms->img1, xpxl2, ypxl2 + 1, fpart(yend) * xgap);
	}
	//main loop
	if (ms->steep)
	{
		int x = xpxl1 + 1;
		while(x < xpxl2 - 1)
		{
			put_pixel(ms->img1, floor(intery), x, rfpart(intery));
			put_pixel(ms->img1, floor(intery)+1, x, fpart(intery));
			intery += ms->gradient;
			x++;
		}
	}
	else
	{
		int x = xpxl1 + 1;
		while(x < xpxl2 - 1)
		{
			put_pixel(ms->img1, x, floor(intery),  rfpart(intery));
			put_pixel(ms->img1, x, floor(intery) + 1, fpart(intery));
			intery += ms->gradient;
			x++;
		}
	}
}


void	put_pixel(t_img *img, int x, int y, double a)
{
	char	*color;
	int		alpha;
	int		red;
	int		green;
	int		blue;

	if (a == 0)
		return ;
	if ((y * WIN_W + x) * 4 - 1 < 0 ||
		(y * WIN_W + x) * 4 - 1 > WIN_H * WIN_W * 4)
		return ;
	color = &img->addr[(y * WIN_W + x) * 4 - 1];
	alpha = 255 * a;
	red = 255;
	green = 255;
	blue = 255;
	*color++ = alpha;
	*color++ = red;
	*color++ = green;
	*color = blue;
}
*/