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

void	fx_mlx_pixel_put(t_img *data, int x, int y, int color);
int		buttons(int keycode, t_ptrs *ptrs);
int		square(int keycode, t_ptrs *ptrs);
int		handle_x_button(t_ptrs *data);
int		clear_window(t_ptrs *mlxs);
int		pixelputz(t_ptrs *ptrs);
int		hi(int keycode);
int		plot_cube(t_ptrs *ptrs);
int		mousers(int keycode, int x, int y, t_ptrs *ptrs);
int		plot_line(t_ptrs *ptrs, int x1, int x2, int y1, int y2);
int		plot_liney(t_ptrs *mlxs, int x1, int x2, int y1, int y2);
		//return (mlx_string_put(ptrs->mlx, ptrs->win, 10, 20, 0x00FF00FF, "Hello there"));
		//int     mlx_mouse_get_pos(void *mlx_ptr, void *win_ptr, int *x, int *y);

int	main(void)
{
	t_ptrs	mlxs;
	t_img	img1;

	mlxs.mlx = mlx_init();
	mlxs.win = mlx_new_window(mlxs.mlx, 1000, 700, "Hello world!");
	mlxs.offx = 0;
	mlxs.offy = 0;
	mlxs.color = 0x00FFFFFF;
	mlxs.img1 = &img1;
	img1.img = mlx_new_image(mlxs.mlx, 1000, 700);
	img1.addr = mlx_get_data_addr(img1.img, &img1.bits_per_pixel, &img1.line_length, &img1.endian);
	printf("Data Adress: %p\nBitsPerPix = %i\nLineLength = %i\nEndian = %i\n", img1.addr, img1.bits_per_pixel, img1.line_length, img1.endian);
	//mlx_loop_hook(mlxs.win, square, &mlxs);
	mlx_hook(mlxs.win, 2, 1L<<0, buttons, &mlxs);
	mlx_hook(mlxs.win, 17, 0, &handle_x_button, &mlxs);
	mlx_mouse_hook(mlxs.win, mousers, &mlxs);
	mlx_loop(mlxs.mlx);
}

int		plot_cube(t_ptrs *ptrs)
{
	int	i;
	int	a;
	int b;
	int	tempcolor;
	int angle;

	angle = 30;
	a = 50;
	i = 250;
	b = 450;
	plot_line(ptrs, a, i, i, i); //draws a line from a to i at column i
	plot_line(ptrs, a, i, b, b); //draws a line from a to i at column b
	plot_liney(ptrs, i, b, i, i); //draws a column from b to i at line i
	plot_liney(ptrs, i, b, a, a); //draws a column from b to i at line a
	tempcolor = ptrs->color;
	//ptrs->color = 0x00FF0000;
	plot_line(ptrs, a, (i + cos(angle) * 50), i, (i + sin(angle) * 50));
	plot_line(ptrs, a, (i + cos(angle) * 50), b, (b + sin(angle) * 50));
	plot_line(ptrs, i, (b + cos(angle) * 50), i, (i + sin(angle) * 50));
	plot_line(ptrs, i, (b + cos(angle) * 50), b, (b + sin(angle) * 50));

	i += 150;
	a += 205;
	b += 205;
	plot_line(ptrs, a, i + 55, i, i);
	plot_line(ptrs, a, i + 55, i/2, i/2);
	plot_liney(ptrs, i - 200, b - 257, i + 55, i + 55); //draws a column from b to i at line i
	plot_liney(ptrs, i - 200, b - 257, i - 142, i - 142);
	//plot_line(ptrs, a, i, b, b); //draws a line from a to i at column b
	//plot_liney(ptrs, i, b, i, i); //draws a column from b to i at line i
	//plot_liney(ptrs, i, b, a, a); //draws a column from b to i at line a
	ptrs->color = tempcolor;

	/*
	i = 250;
	plot_line(ptrs, 50, 250, 250, 250);
	plot_line(ptrs, 50, 250, 450, 450);
	plot_liney(ptrs, 250, 450, 250, 250);
	plot_liney(ptrs, 250, 450, 50, 50);
	*/

	return (i);
}

int		plot_line(t_ptrs *mlxs, int x1, int x2, int y1, int y2) //based on https://en.wikipedia.org/wiki/Line_drawing_algorithm
{
	int	dx;
	int	dy;
	int	y;
	int	i;

	dx = x2 - x1;
	dy = y2 - y1;
	i = x1;

	while (i <= x2)
	{
		y = y1 + dy * (i - x1) / dx;
		mlx_pixel_put(mlxs->mlx, mlxs->win, i, y, mlxs->color);
		i++;
	}
	return (i);
}

int		plot_liney(t_ptrs *mlxs, int x1, int x2, int y1, int y2) //based on https://en.wikipedia.org/wiki/Line_drawing_algorithm
{
	int	dx;
	int	dy;
	int	y;
	int	i;

	dx = x2 - x1;
	dy = y2 - y1;
	i = x1;

	while (i <= x2)
	{
		y = y1 + dy * (i - x1) / dx;
		mlx_pixel_put(mlxs->mlx, mlxs->win, y, i, mlxs->color);
		i++;
	}
	return (i);
}


int		mousers(int keycode, int x, int y, t_ptrs *ptrs)
{
		if (keycode == 1)
			mlx_string_put(ptrs->mlx, ptrs->win, 10, 20, 0x00FF00FF, "Hello there");
		//int     mlx_mouse_get_pos(void *mlx_ptr, void *win_ptr, int *x, int *y);
		mlx_string_put(ptrs->mlx, ptrs->win, x, y, ptrs->color, "GENERAL KENOBI!");
		printf("Keycode: %i, X = %i, Y = %i Colors = %i\n", keycode, x, y, ptrs->color);
		return (3);
}

int	pixelputz(t_ptrs *ptrs)
{
	int	i;

	i = 0;
	while (i < 80000)
	{
		*(unsigned int*)(ptrs->img1->addr + i) = 0x000000FF;
		i += 4;
	}
	mlx_put_image_to_window(ptrs->mlx, ptrs->win, ptrs->img1->img, 0, 0);
	return (i);

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
		return (pixelputz(ptrs));
	if (keycode == 113)
		ptrs->color = 0x00FFFFFF;
	if (keycode == 110) //n
		ptrs->color = 0x00000000;
	if (keycode == 107)
		return (mlx_clear_window(ptrs->mlx, ptrs->win));
	if (keycode == 121) //y
		return ((plot_line(ptrs, 150, 400, 20, 180)));
	if (keycode == 120) //x
		return ((plot_line(ptrs, 150, 400, 180, 20)));
	if (keycode == 49) //key1
		return ((plot_cube(ptrs)));
	if (keycode == 104) //h
	/*{
		mlx_string_put(ptrs->mlx, ptrs->win, 10, 20, 0x00FF00FF, "hello there");
		return (mlx_string_put(ptrs->mlx, ptrs->win, 100 + ptrs->offx, 0 + ptrs->offy, ptrs->color, "GENERAL KENOBI!"));
	}*/
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

void	fx_mlx_pixel_put(t_img *data, int x, int y, int color)
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
