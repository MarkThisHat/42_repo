/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:18:22 by maalexan          #+#    #+#             */
/*   Updated: 2023/03/01 10:30:49 by maalexan         ###   ########.fr       */
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

