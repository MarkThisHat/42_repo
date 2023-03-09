/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:20:52 by maalexan          #+#    #+#             */
/*   Updated: 2023/03/07 10:47:28 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	position_img(t_mlxs *ms)
{
	int		average;
	int		ratiow;
	int		ratioh;

	average = (ms->higher + ms->lower) / 2;
	ratiow = WIN_W / ms->col;
	ratioh = WIN_H / ms->row;
	ms->scale = ratioh / 3;
	if (ratiow < ratioh)
		ms->scale = ratiow / 3;
	if (!ms->scale)
		ms->scale = 1;
	ms->mapspot = (ratiow + ratioh) / 1.75;
	if (!average)
		average = 1;
	set_matrixes(ms, average);
}

void	draw_map(t_mlxs *ms)
{
	t_line	line;
	int		i;
	int		j;
	int		color;

	i = 0;
	line.factor = 0;
	while (i < ms->col)
	{
		j = 0;
		while (j < ms->row)
		{
			color = ms->cart[i][j].color;
			(*ms->fad)->color = see_color(ms, color, ms->cart[i][j].z);
			if ((i + 1) != ms->col)
				draw_line(ms, ms->cart[i][j], ms->cart[i + 1][j], &line);
			if ((j + 1) != ms->row)
				draw_line(ms, ms->cart[i][j], ms->cart[i][j + 1], &line);
			j++;
		}
		i++;
	}
	ms->dye = 0;
}

void	draw_line(t_mlxs *ms, t_coord ini, t_coord fin, t_line *l)
{
	int	average;
	int	temp;

	l->x0 = ini.xyz[0] + ms->width_adj;
	l->x1 = fin.xyz[0] + ms->width_adj;
	l->y0 = ini.xyz[1] + ms->height_adj;
	l->y1 = fin.xyz[1] + ms->height_adj;
	if (ms->dye && (ini.z || fin.z))
	{
		average = (ms->higher + ms->lower) / 2;
		if (!average)
			average = 1;
		l->factor = (ms->higher - ms->lower) / average;
		if (!l->factor)
			l->factor = 1;
		if (l->factor < 0)
			l->factor *= -1;
		temp = ms->dye;
		ms->dye += put_colors(ms->color, l->factor);
	}
	put_line(ms, l);
	if (ms->dye)
		ms->dye = temp;
	l->factor = 0;
}

void	put_pixel(t_img *img, int x, int y, int factor)
{
	char			*painter;
	unsigned int	color;
	int				target;

	target = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
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

void	clear_img(t_img *img)
{
	char			*painter;
	char			*target;

	target = img->addr + (WIN_H * img->line_length);
	painter = img->addr;
	while(painter < target + 1)
	{
		*(unsigned int*)painter = 0;
		painter++;
	}
}
