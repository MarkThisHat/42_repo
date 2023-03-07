/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:49:16 by maalexan          #+#    #+#             */
/*   Updated: 2023/03/07 11:13:37 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

int		invert_endian(int color)
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

int		see_color(t_mlxs *ms, int color, int z)
{
	if (color)
		return (color);
	if (ms->dye && z)
		return (ms->dye);
	return (ms->color);
}
