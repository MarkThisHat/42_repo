/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:22:38 by maalexan          #+#    #+#             */
/*   Updated: 2023/03/10 15:42:19 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	fad_toggle(t_mlxs *ms)
{
	if (ms->toggle == 42)
	{
		ms->fad = &ms->img2;
		(*ms->fad)->img = mlx_new_image(ms->mlx, WIN_W, WIN_H);
		(*ms->fad)->addr = mlx_get_data_addr(\
		(*ms->fad)->img, &(*ms->fad)->bits_per_pixel, \
		&(*ms->fad)->line_length, &(*ms->fad)->endian);
		ms->toggle = 0;
		return ;
	}
	if (!ms->toggle)
	{
		ms->fad = &ms->img1;
		ms->toggle = 1;
	}
	else
	{
		ms->fad = &ms->img2;
		ms->toggle = 0;
	}
}

void	redraw_map(t_mlxs *ms)
{
	mlx_clear_window(ms->mlx, ms->win);
	clear_img(*ms->fad);
	fad_toggle(ms);
	draw_map(ms);
	mlx_put_image_to_window(ms->mlx, ms->win, (*ms->fad)->img, 0, 0);
	top_menu(ms);
}

void	top_menu(t_mlxs *ms)
{
	mlx_string_put(ms->mlx, ms->win, 125, 10, 0xFF0000, "MENU");
	mlx_string_put(ms->mlx, ms->win, 42, 30, 0xFF00FF, "Backspace key:");
	mlx_string_put(ms->mlx, ms->win, 150, 30, 0xFF, "Reset position");
	mlx_string_put(ms->mlx, ms->win, 42, 50, 0xFF00FF, "Arrow keys:");
	mlx_string_put(ms->mlx, ms->win, 150, 50, 0xFF, "Move Map");
	mlx_string_put(ms->mlx, ms->win, 42, 70, 0xFF00FF, "U and J keys:");
	mlx_string_put(ms->mlx, ms->win, 150, 70, 0xFF, "Rotate X axis");
	mlx_string_put(ms->mlx, ms->win, 42, 90, 0xFF00FF, "I and K keys:");
	mlx_string_put(ms->mlx, ms->win, 150, 90, 0xFF, "Rotate Y axis");
	mlx_string_put(ms->mlx, ms->win, 42, 110, 0xFF00FF, "O and L keys:");
	mlx_string_put(ms->mlx, ms->win, 150, 110, 0xFF, "Rotate Z axis");
	mlx_string_put(ms->mlx, ms->win, 42, 130, 0xFF00FF, "Z and X keys:");
	mlx_string_put(ms->mlx, ms->win, 150, 130, 0xFF, "Modify Z scale");
	mlx_string_put(ms->mlx, ms->win, 42, 150, 0xFF00FF, "R, G and B keys:");
	mlx_string_put(ms->mlx, ms->win, 150, 150, 0xFF, "Add respective color");
	mlx_string_put(ms->mlx, ms->win, 42, 170, 0xFF00FF, "Scroll or + - :");
	mlx_string_put(ms->mlx, ms->win, 150, 170, 0xFF, "Zoom in/out");
	mlx_string_put(ms->mlx, ms->win, 42, 190, 0xFF00FF, "Left click:");
	mlx_string_put(ms->mlx, ms->win, 150, 190, 0xFF, "Position Map");
	mlx_string_put(ms->mlx, ms->win, 42, 210, 0xFF00FF, "Right click:");
	mlx_string_put(ms->mlx, ms->win, 150, 210, 0xFF, "Conic project");
	bottom_menu(ms);
}

void	bottom_menu(t_mlxs *ms)
{
	char	*str;

	mlx_string_put(ms->mlx, ms->win, 80, WIN_H - 180, 0xFF00, \
	"TRANSLATION TABLE");
	mlx_string_put(ms->mlx, ms->win, 42, WIN_H - 160, 0xFF00FF, \
	"Q and A keys:");
	mlx_string_put(ms->mlx, ms->win, 150, WIN_H - 160, 0x22FF, "Add/rem X -> ");
	str = ft_itoa(ms->translations[0]);
	mlx_string_put(ms->mlx, ms->win, 250, WIN_H - 160, 0xFFF04D, str);
	free(str);
	mlx_string_put(ms->mlx, ms->win, 42, WIN_H - 140, 0xFF00FF, \
	"W and S keys:");
	mlx_string_put(ms->mlx, ms->win, 150, WIN_H - 140, 0x22FF, "Add/rem Y -> ");
	str = ft_itoa(ms->translations[1]);
	mlx_string_put(ms->mlx, ms->win, 250, WIN_H - 140, 0xFFF04D, str);
	free(str);
	mlx_string_put(ms->mlx, ms->win, 42, WIN_H - 120, 0xFF00FF, \
	"E and D keys:");
	mlx_string_put(ms->mlx, ms->win, 150, WIN_H - 120, 0x22FF, "Add/rem Z -> ");
	str = ft_itoa(ms->translations[2]);
	mlx_string_put(ms->mlx, ms->win, 250, WIN_H - 120, 0xFFF04D, str);
	free(str);
	cone_menu(ms);
}

void	cone_menu(t_mlxs *ms)
{
	mlx_string_put(ms->mlx, ms->win, 42, 230, 0xFF00FF, "Right click:");
	mlx_string_put(ms->mlx, ms->win, 150, 230, 0xFF, "Z");
}
