/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:44:21 by maalexan          #+#    #+#             */
/*   Updated: 2023/02/23 12:44:42 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		keybonus(int keycode, t_mlxs *ms)
{
	if (keycode == P_KEY)
	{
		ms->angle += 0.1;
		//printf("%f\n", ms->angle);
	}
	if (keycode == O_KEY)
	{
		ms->angle -= 0.1;
		//printf("%f\n", ms->angle);
	}
	if (keycode == N_PLU_K)
		ms->scale -= 10;
	if (keycode == N_MIN_K)
		ms->scale += 10;
	if(keycode == ARW_U_K)
		ms->focus_x -= 10;
	if(keycode == ARW_D_K)
	{
		ms->focus_x += 10;
		ft_printf("focX%i\n", ms->focus_x);
	}
	if(keycode == ARW_L_K)
	{
		ms->focus_y -= 10;
		ft_printf("focY%i\n", ms->focus_y);
	}
	if(keycode == ARW_R_K)
		ms->focus_y += 10;
	if(keycode == K_KEY)
	{
		ms->tilt += 0.1;
		printf("%f\n", ms->tilt);
	}
	if(keycode == L_KEY)
	{
		ms->tilt -= 0.1;
		printf("%f\n", ms->tilt);
	}
	if(keycode == R_KEY)
		ms->color = 0xFFFF0000;
	if(keycode == G_KEY)
		ms->color = 0xFF00FF00;
	if(keycode == B_KEY)
		ms->color = 0xFF0000FF;
	ft_printf("%i\n", keycode);
	mlx_clear_window(ms->mlx, ms->win);
	clear_img(*ms->fad);
	fad_toggle(ms);
	draw_map(ms);
	mlx_put_image_to_window(ms->mlx, ms->win, (*ms->fad)->img, 0, 0);*/
	return (keycode);
}

void	fad_toggle(t_mlxs *ms)
{
	if (ms->toggle == 42)
	{
		ms->fad = &ms->img2;
		(*ms->fad)->img = mlx_new_image(ms->mlx, WIN_W, WIN_H);
		(*ms->fad)->addr = mlx_get_data_addr((*ms->fad)->img, &(*ms->fad)->bits_per_pixel, &(*ms->fad)->line_length, &(*ms->fad)->endian);
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
