#include "mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct	s_ptrs {
	void	*mlx;
	void	*win;
	t_img	*img1;
	t_img	*img2;
	int		x;
	int		y;
	int		offx;
	int		offy;
	int		next;
	int		color;
}			t_ptrs;

void	fx_mlx_pixel_put(t_data *data, int x, int y, int color);
int		buttons(int keycode, t_ptrs *ptrs);
int		square(int keycode, t_ptrs *ptrs);
int		handle_x_button(t_ptrs *data);
int		clear_window(t_ptrs *mlxs);
int		hi(int keycode);

int	main(void)
{
	t_ptrs	mlxs;
	t_img	img1;

	mlxs.mlx = mlx_init();
	mlxs.win = mlx_new_window(mlxs.mlx, 1000, 700, "Hello world!");
	mlxs.offx = 0;
	mlxs.offy = 0;
	mlxs.color = 0x00FFFFFF;
	mlxs->img1 = &img1;
	img1.img = mlx_new_image(mlxs.mlx, 1000, 700);
	img1.addr = mlx_get_data_addr(img1.img, &img1.bits_per_pixel, &img1.line_length, &img1.endian);
	printf("Data Adress: %s\nBitsPerPix = %i\nLineLength = %i\nEndian = %i\n", img1.bits_per_pixel, img1.line_length, img1.endian);
	//mlx_loop_hook(mlxs.win, square, &mlxs);
	mlx_hook(mlxs.win, 2, 1L<<0, buttons, &mlxs);
	mlx_hook(mlxs.win, 17, 0, &handle_x_button, &mlxs);
	mlx_mouse_hook(mlxs.win, buttons, &mlxs);
	mlx_loop(mlxs.mlx);
}

int	square(int keycode, t_ptrs *ptrs)
{
	ptrs->x = 100;
	ptrs->y = 0;
	ptrs->next = 200;
	if (keycode == 119 || keycode == 65362)
	{
		ptrs->offy -= 10;
	}
	if (keycode == 115 || keycode == 65364)
	{
		ptrs->offy += 10;
	}
	if (keycode == 97 || keycode == 65361)
	{
		ptrs->offx -= 10;
	}
	if (keycode == 100 || keycode == 65363)
	{
		ptrs->offx += 10;
	}
	if (keycode == 98)
		ptrs->color = 0x000000FF;
	if (keycode == 114)
		ptrs->color = 0x00FF0000;
	if (keycode == 103)
		ptrs->color = 0x0000FF00;
	if (keycode == 99)
		return (clear_window(ptrs));
	if (keycode == 112)
		return (circle(1, ptrs));
	if (keycode == 113)
		ptrs->color = 0x00FFFFFF;
	while (ptrs->y < ptrs->next)
	{
		mlx_pixel_put(ptrs->mlx, ptrs->win, ptrs->x + ptrs->offx, ptrs->y + ptrs->offy, ptrs->color);
		ptrs->y++;
	}
	while (ptrs->x < ptrs->next * 1.5)
	{
		mlx_pixel_put(ptrs->mlx, ptrs->win, ptrs->x + ptrs->offx, ptrs->y + ptrs->offy, ptrs->color);
		ptrs->x++;
	}
	while (ptrs->x && ptrs->y)
	{
		//mlx_pixel_put(ptrs->mlx, ptrs->win, ptrs->x, ptrs->y, ptrs->color);
		ptrs->x--;
		ptrs->y--;
	}
	while (ptrs->x < ptrs->next * 1.5)
	{
	mlx_pixel_put(ptrs->mlx, ptrs->win, ptrs->x + ptrs->offx, ptrs->y + ptrs->offy, ptrs->color);
		ptrs->x++;
	}
	while (ptrs->y < ptrs->next)
	{
	mlx_pixel_put(ptrs->mlx, ptrs->win, ptrs->x + ptrs->offx, ptrs->y + ptrs->offy, ptrs->color);
		ptrs->y++;
	}
	return (ptrs->next);
}

int	hi(int keycode)
{
	printf("Hi! %i\n", keycode);
	return (keycode);
}

int	buttons(int keycode, t_ptrs *ptrs)
{
	if (keycode == 65307)
	{
		handle_x_button(ptrs);
	}
	else
	{
		printf("%i\n", keycode);
		square(keycode, ptrs);
	}
	return (1);
}

void	fx_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	handle_x_button(t_ptrs *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit (0);
	return (0);
}

int	clear_window(t_ptrs *mlxs)
{
	int	i;
	int	j;

	i = 0;
	while (i < 1000)
	{
		j = 0;
		while (j < 700)
		{
			mlx_pixel_put(mlxs->mlx, mlxs->win, i, j, 0);
			j++;
		}
		i++;
	}
	return (2);
}