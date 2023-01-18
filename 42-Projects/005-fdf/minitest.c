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
}			t_ptrs;

void	fx_mlx_pixel_put(t_data *data, int x, int y, int color);
int	close(int keycode, t_ptrs *ptrs);
int	hi(int keycode);

int	main(void)
{
	t_ptrs	mlxs;
	int		i;
	int		pixa;
	t_data	turt;

	i = 0;
	mlxs.mlx = mlx_init();
	mlxs.win = mlx_new_window(mlxs.mlx, 1000, 700, "Hello world!");
	turt.img = mlx_new_image(mlxs.mlx, 300, 300);
	turt.addr = mlx_get_data_addr(turt.img, &turt.bits_per_pixel, &turt.line_length, &turt.endian);
	int color = 0x0000FF00;
	pixa = i;
	while (i < 170)
	{
		fx_mlx_pixel_put(&turt, pixa, i, color++);
		mlx_pixel_put(mlxs.mlx, mlxs.win, pixa + 30, i, color);
		i++;
	}
	pixa = i;
	i = 0;
	color = ~color;
	while (i < 170)
	{
		fx_mlx_pixel_put(&turt, i, pixa, color--);
		i++;
	}
	pixa = i;
	color = ~color;
	while (i > 0)
	{
		fx_mlx_pixel_put(&turt, pixa, i, color++);
		i--;
	}
	color = ~color;
	while (pixa)
	{
		fx_mlx_pixel_put(&turt, pixa, i, color--);
		pixa--;
	}
	mlx_put_image_to_window(mlxs.mlx, mlxs.win, turt.img, 200, 300);
	mlx_hook(mlxs.win, 2, 1L<<0, close, &mlxs);
	mlx_mouse_hook(mlxs.win, hi, &mlxs);
	mlx_loop(mlxs.mlx);
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