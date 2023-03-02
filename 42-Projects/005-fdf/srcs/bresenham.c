/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:29:47 by maalexan          #+#    #+#             */
/*   Updated: 2023/03/01 11:47:30 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	put_pixel(t_img *img, int x, int y, int factor)
{
	char			*painter;
	unsigned int	color;
	int				target;

	target = (x * img->line_length) + (y * (img->bits_per_pixel / 8));
	if (target < 0 || target > (WIN_H * img->line_length))
		return ;
	painter = img->addr + target;
	color = img->color - (img->color << 24);
	color += 0xFF000000;
	if (factor)
		color += add_factor(color, factor);
	if (img->endian)
		color = invert_endian(color);
	*(unsigned int*)painter = color;
}

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
	int x;
	int y;

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

void put_line(t_mlxs *ms, t_line *l)
{
	t_line p;

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

void	keep_bound(t_line *l)
{
	if (l->x0 < 0)
		l->x0 = 0;
	if (l->x0 >= WIN_H)
		l->x0 = WIN_H - 1;
	if (l->y0 < 0)
		l->y0 = 0;
	if (l->y0 >= WIN_W)
		l->y0 = WIN_W - 1;
	if (l->x1 < 0)
		l->x1 = 0;
	if (l->x1 >= WIN_H)
		l->x1 = WIN_H - 1;
	if (l->y1 < 0)
		l->y1 = 0;
	if (l->y1 >= WIN_W)
		l->y1 = WIN_W - 1;
}

/****\
let's leave this out at first
    // calculate the length of the line
    line_length = sqrt(l->dx * l->dx + l->dy * l->dy);

    while (1)
    {
        // check if the current point is outside of the image bounds
        if (x0 < 0 || x0 >= img->width || y0 < 0 || y0 >= img->height) break;

        // set the pixel at the current position
        img->addr[y0 * img->line_length + x0 * (img->bits_per_pixel / 8)] = color;

        int e2 = 2 * err;

        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }

        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }

        // check if the length of the line exceeds the dimensions of the image
        if (sqrt(pow(x0-x1, 2) + pow(y0-y1, 2)) > line_length)
			break;
    }
}

//chat gpt suggestion:

void draw_line(int x0, int y0, int x1, int y1, int color, t_data *img)
{
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx = x0 < x1 ? 1 : -1;
	int sy = y0 < y1 ? 1 : -1;
	int err = dx - dy;

	// check if points A and B are inside the image bounds, and adjust them accordingly
	if (x0 < 0)
		x0 = 0;
	if (x0 >= img->width)
		x0 = img->width - 1;
	if (y0 < 0)
		y0 = 0;
	if (y0 >= img->height)
		y0 = img->height - 1;
	if (x1 < 0)
		x1 = 0;
	if (x1 >= img->width)
		x1 = img->width - 1;
	if (y1 < 0)
		y1 = 0;
	if (y1 >= img->height)
		y1 = img->height - 1;

	// calculate the length of the line
	int line_length = sqrt(dx*dx + dy*dy);

	while (1)
	{
		// check if we have reached the end of the line
		if (x0 == x1 && y0 == y1) break;

		// set the pixel at the current position
		if (x0 >= 0 && x0 < img->width && y0 >= 0 && y0 < img->height)
			img->addr[y0 * img->line_length + x0 * (img->bits_per_pixel / 8)] = color;

		int e2 = 2 * err;

		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}

		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}

		// check if the length of the line exceeds the dimensions of the image
		if (sqrt(pow(x0-x1, 2) + pow(y0-y1, 2)) > line_length) break;
	}
	}

//version TWO

void draw_line(int x0, int y0, int x1, int y1, int color, t_data *img)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;

    // check if points A and B are inside the image bounds, and adjust them accordingly
    if (x0 < 0) x0 = 0;
    if (x0 >= img->width) x0 = img->width - 1;
    if (y0 < 0) y0 = 0;
    if (y0 >= img->height) y0 = img->height - 1;
    if (x1 < 0) x1 = 0;
    if (x1 >= img->width) x1 = img->width - 1;
    if (y1 < 0) y1 = 0;
    if (y1 >= img->height) y1 = img->height - 1;

    // calculate the length of the line
    int line_length = sqrt(dx*dx + dy*dy);

    while (1)
    {
        // check if the current point is outside of the image bounds
        if (x0 < 0 || x0 >= img->width || y0 < 0 || y0 >= img->height) break;

        // set the pixel at the current position
        img->addr[y0 * img->line_length + x0 * (img->bits_per_pixel / 8)] = color;

        int e2 = 2 * err;

        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }

        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }

        // check if the length of the line exceeds the dimensions of the image
        if (sqrt(pow(x0-x1, 2) + pow(y0-y1, 2)) > line_length) break;
    }
}



\*****/