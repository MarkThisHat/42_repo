#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct	s_ptrs {
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		next;
}			t_ptrs;

void	fx_mlx_pixel_put(t_data *data, int x, int y, int color);
int		close(int keycode, t_ptrs *ptrs);
int		movement(int keycode, t_ptrs *ptrs);
int		hi(int keycode);

int	main(void)
{
	t_ptrs	mlxs;

	mlxs.mlx = mlx_init();
	mlxs.win = mlx_new_window(mlxs.mlx, 1000, 700, "Hello world!");
	mlxs.x = 100;
	mlxs.y = 0;
	mlxs.next = 170;
	movement(1, &mlxs);
	mlx_hook(mlxs.win, 2, 1L<<0, close, &mlxs);
	mlx_mouse_hook(mlxs.win, hi, &mlxs);
	mlx_loop(mlxs.mlx);
}

int	movement(int keycode, t_ptrs *ptrs)
{
	int	color = 0x0000FF00;
	if (!keycode)
		return (0);
	while (ptrs->y < ptrs->next)
	{
		mlx_pixel_put(ptrs->mlx, ptrs->win, ptrs->x, ptrs->y, color);
		ptrs->y++;
	}
	return (ptrs->next);
}

int	hi(int keycode)
{
	printf("Hi! %i\n", keycode);
	return (keycode);
}

int	close(int keycode, t_ptrs *ptrs)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(ptrs->mlx, ptrs->win);
		exit (0);
	}
	else
		printf("%i\n", keycode);
	return (1);
}

void	fx_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}