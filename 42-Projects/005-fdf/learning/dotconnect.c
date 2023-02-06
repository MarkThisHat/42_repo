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

	target = (x * img->line_length) + (y * (img->bits_per_pixel / 8));
	//ft_printf("img->line_length %i img->bits_per_pixel %i x %i y %i WIN_H * WIN_W %i target %i\n",img->line_length, img->bits_per_pixel, x, y, WIN_H * WIN_W, target);
	if (target < 0 || target > (WIN_H * img->line_length))
		return ;
	//this draws most of the last line of the screen: target = (WIN_H * img->line_length) - (11 * img->line_length);
	if (img->endian)
		img->color = invert_endian(img->color);
	painter = img->addr + target;
	color = img->color - (img->color << 24);
	//ft_printf("target x is %i and target y is %i\n", x, y);
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


plotLine(x0, y0, x1, y1)
    dx = abs(x1 - x0)
    sx = x0 < x1 ? 1 : -1
    dy = -abs(y1 - y0)
    sy = y0 < y1 ? 1 : -1
    error = dx + dy
    
    while true
        plot(x0, y0)
        if x0 == x1 && y0 == y1 break
        e2 = 2 * error
        if e2 >= dy
            if x0 == x1 break
            error = error + dy
            x0 = x0 + sx
        end if
        if e2 <= dx
            if y0 == y1 break
            error = error + dx
            y0 = y0 + sy
        end if
    end while



	plotLineLow(x0, y0, x1, y1)
	dx = x1 - x0
	dy = y1 - y0
	yi = 1
	if (dy < 0)
	{
		yi = -1
		dy = -dy
	}
	d = (2 * dy) - dx
	y = y0

	x = x0
	while (x < x1)
	{
		plot(x, y)
		if (d > 0)
		{
			y = y + yi
			d = d + (2 * (dy - dx))
		else
			d = d + 2*dy
		}
		x++;
	}

	//By switching the x and y axis an implementation for positive or negative steep slopes can be written as

	plotLineHigh(x0, y0, x1, y1)
	dx = x1 - x0
	dy = y1 - y0
	xi = 1
	if (dx < 0)
	{
		xi = -1
		dx = -dx
	}
	d = (2 * dx) - dy
	x = x0

	y = y0;
	while (y0 < y1)
	{
		plot(x, y)
		if (d > 0)
		{
			x = x + xi
			d = d + (2 * (dx - dy))
		else
			d = d + 2 * dx
		}
		y++;
	}

//A complete solution would need to detect whether x1 > x0 or y1 > y0 and reverse the input coordinates before drawing, thus

plotLine(x0, y0, x1, y1)
    if abs(y1 - y0) < abs(x1 - x0)
	{
        if x0 > x1
		{
            plotLineLow(x1, y1, x0, y0)
        else
            plotLineLow(x0, y0, x1, y1)
        }
    else
        if y0 > y1
		{
            plotLineHigh(x1, y1, x0, y0)
        else
            plotLineHigh(x0, y0, x1, y1)
        }
    }
/*

//redundancies eliminated

	plotLineLow(x0, y0, x1, y1)
//	plotLineHigh(x0, y0, x1, y1)
	dx = x1 - x0
//	dx = x1 - x0
	dy = y1 - y0
//	dy = y1 - y0
	yi = 1
//	xi = 1
	if (dy < 0)
//	if (dx < 0)
	{
//	{
		yi = -1
//		xi = -1
		dy = -dy
//		dx = -dx
	}
//	}
	d = (2 * dy) - dx
//	d = (2 * dx) - dy
	y = y0
//	x = x0
	x = x0
//	y = y0;
	while (x < x1)
//	while (y0 < y1)
	{
//	{
		plot(x, y)
//		plot(x, y)
		if (d > 0)
//		if (d > 0)
		{
//		{
			y = y + yi
//			x = x + xi
			d = d + (2 * (dy - dx))
//			d = d + (2 * (dx - dy))
		else
//		else
			d = d + 2*dy
//			d = d + 2 * dx
		}
//		}
		x++;
//		y++;
	}
//	}

//sidebyside
	plotLineHIGHLow(x0, y0, x1, y1)
	dx = x1 - x0

	dy = y1 - y0
	yi = 1//xi = 1
	if (dy < 0) //(dx < 0)
	{
		yi = -1// xi = -1
		dy = -dy// dx = -dx
	}
	d = (2 * dy) - dx//	d = (2 * dx) - dy
	y = y0//x = x0
	x = x0//y = y0;
	while (x < x1)//while (y0 < y1)
	{
		plot(x, y)
		if (d > 0)
		{
			y = y + yi//x = x + xi
			d = d + (2 * (dy - dx))//d = d + (2 * (dx - dy))
		else
			d = d + 2 * dy//d = d + 2 * dx
		}
		x++;//y++;
	}

//wildcarding
plotLineHIGHLow(x0, y0, x1, y1)
	dx = x1 - x0
	dy = y1 - y0
	
this might be doable outside
	n = 1//replace xi and yi with n = 1
	if (dn < 0)//(dy < 0) | (dx < 0)
	{
		n = -1//yi = -1 | xi = -1
		dn = -dn // dy = -dy | dx = -dx
	}
	d = (2 * dn) - dn//d = (2 * dy) - dx |	d = (2 * dx) - dy
	
this might be too confusing
	y = y0//x = x0
	x = x0//y = y0;
	while (x < x1)//while (y0 < y1)
	{
		plot(x, y)
		if (d > 0)
		{
			y = y + yi//x = x + xi
			d = d + (2 * (dy - dx))//d = d + (2 * (dx - dy))
		else
			d = d + 2 * dy//d = d + 2 * dx
		}
		x++;//y++;
	}

// amalgamating
plotLineHIGHLow(x0, y0, x1, y1)
{
	dx = x1 - x0
	dy = y1 - y0
	
this might be doable outside
	n = 1//replace xi and yi with n = 1
	if (dn < 0)//(dy < 0) | (dx < 0)
	{
		n = -1//yi = -1 | xi = -1
		dn = -dn // dy = -dy | dx = -dx
	}
	d = (2 * dn) - dn//d = (2 * dy) - dx |	d = (2 * dx) - dy
	
this might be too confusing
	y = y0//x = x0
	x = x0//y = y0;
while (x < x1)//while (y0 < y1)
	{
		plot(x, y)
		if (d > 0)
		{
			y = y + yi//x = x + xi
			d = d + (2 * (dy - dx))//d = d + (2 * (dx - dy))
		else
			d = d + 2 * dy//d = d + 2 * dx
		}
		x++;//y++;
	}
	*/