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

void	swap(double *a, double *b)
{
	double temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

double	get_fract(double n)
{
	return (ceil(n) - n);
}
