/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:18:22 by maalexan          #+#    #+#             */
/*   Updated: 2023/03/07 11:29:58 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

int		mouse_group(int keycode, int x, int y, t_mlxs *ms)
{
	if (keycode == 1)
		adjust_ambit(ms, y, x);
	if (keycode == 4)
		bonus_scale(ms, 0);
	if (keycode == 5)
		bonus_scale(ms, 1);
    if (keycode == 3)
		conic_sans(ms, 0, 0, 50);
	redraw_map(ms);
	return (keycode);
}
