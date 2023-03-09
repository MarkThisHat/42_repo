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

int my_loop_function(t_mlxs *ms)
{
    int x, y;

   // mlx_mouse_pos(ms, &x, &y);
    mlx_mouse_get_pos(ms->mlx, ms->win, &x, &y);
    mlx_pixel_put(ms->mlx, ms->win, x, y, 0xFF0000); // Red pixel at mouse position
    ft_printf("loop func got called");
    return (2);
}

int my_mouse_hook(int button, int x, int y, t_mlxs *ms)
{
    (void)x;
    (void)y;
    if (button == 3) // Right mouse button clicked
    {
        mlx_loop_hook(ms, my_loop_function, ms);
        ft_printf("button 3 function called\n");
    }
    else if (button == 2) // Right mouse button released
    {
        mlx_loop_hook(ms, NULL, ms);
        ft_printf("button 2 function called\n");
    }
    return (0);
}

int		mouse_group(int keycode, int x, int y, t_mlxs *ms)
{
	ft_printf("k: %i x: %i y: %i\n", keycode, x, y);
	int	xm;
	int	ym;

	xm = 0;
	ym = 0;
	if (keycode == 1)
		adjust_ambit(ms, y, x);
	if (keycode == 4)
		bonus_scale(ms, 0);
	if (keycode == 5)
		bonus_scale(ms, 1);
//	if (keycode == 3)
//		translate_point(ms, x, y);
	redraw_map(ms);
	mlx_mouse_get_pos(ms->mlx, ms->win, &xm, &ym);
	ft_printf("x:%i\ny:%i\n", xm, ym);
//	int	mlx_mouse_move(void *mlx_ptr, void *win_ptr, int x, int y);
//	https://codebrowser.dev/qt5/include/X11/X.h.html
//	https://github.com/D-Programming-Deimos/libX11/blob/master/c/X11/keysymdef.h
	return (keycode + x + y);
}
