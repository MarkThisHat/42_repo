/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:48:41 by maalexan          #+#    #+#             */
/*   Updated: 2023/03/01 10:12:46 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

int		validate_usage(int	argc, char **argv, t_mlxs *ms)
{
	int	fd;
	int	len;

	if (argc != 2)
		leave_program("Usage: <program name> <file.fdf>\n", 2, 1);
	len = ft_strlen(argv[1]);
	if (len < 5 || ft_strncmp(".fdf", &argv[1][len - 4], 5))
		leave_program("Please input a valid <.fdf> file\n", 2, 2);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		leave_program("Error opening file\n", 2, 3);
	if (!count_col(fd, ms))
		leave_program("Can't parse this map\n", 2, 4);
	ft_printf("Map %s has %i rows and %i columns\n", argv[1], ms->row, ms->col);
	close(fd);
	return (1);
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
	mlx_clear_window(ms->mlx, ms->win);
	clear_img(*ms->fad);
	fad_toggle(ms);
	draw_map(ms);
	mlx_put_image_to_window(ms->mlx, ms->win, (*ms->fad)->img, 0, 0);
	mlx_mouse_get_pos(ms->mlx, ms->win, &xm, &ym);
	ft_printf("x:%i\ny:%i\n", xm, ym);
//	int	mlx_mouse_move(void *mlx_ptr, void *win_ptr, int x, int y);
//	https://codebrowser.dev/qt5/include/X11/X.h.html
//	https://github.com/D-Programming-Deimos/libX11/blob/master/c/X11/keysymdef.h
	return (keycode + x + y);
}

int		keypress(int keycode, t_mlxs *ms)
{
	if (keycode == ESC_K)
		close_win(ms);
	else
		keybonus(keycode, ms);
	return (keycode);
}
