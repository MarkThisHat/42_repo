/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:37:28 by maalexan          #+#    #+#             */
/*   Updated: 2023/02/22 18:05:14 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

/**\
void	printmap(t_mlxs *ms)
{
	int i;
	int j;

	i = 0;
	while (i < ms->row)
	{
		j = 0;
		{
			while (j < ms->col)
			{
				//if (ms->cart[i][j].color)
					ft_printf("Row: %i Col: %i has Z of: %i and Color of %i\n", i, j, ms->cart[i][j].z, ms->cart[i][j].color);
					ft_printf("Row: %i Col: %i has Z of: %i and Color of %i\n\n", ms->cart[i][j].xyz[0], ms->cart[i][j].xyz[1], ms->cart[i][j].xyz[2]);
				j++;
			}
		}
		i++;
	}
}
\**/

int	main(int argc, char **argv)
{
	t_mlxs	main_struct;
	t_img	image;
	t_img	image2;

	main_struct.img1 = &image;
	main_struct.img2 = &image2;
	set_struct(&main_struct);
	validate_usage(argc, argv, &main_struct);
	parse_map(&main_struct, argv[1]);
//	printmap(&main_struct);
	int ratiow = WIN_W / main_struct.col;
	int ratioh = WIN_H / main_struct.row;
	main_struct.scale = ratioh / 3;
	if (ratiow < ratioh)
		main_struct.scale = ratiow / 3;
//	scale_matrix(&main_struct, main_struct.scale, 0);
	mlx_setup(&main_struct);
//	draw_map(&main_struct);
//	mlx_put_image_to_window(main_struct.mlx, main_struct.win, main_struct.img1->img, 10, 10);
}

void	set_struct(t_mlxs *ms)
{
	ms->col = 0;
	ms->row = 0;
	ms->color = 0xFFFFFFFF;
	ms->toggle = 42;
	ms->fad = &ms->img1;
	ms->img2->img = NULL;
	ms->angle = 0.955323;
	crosswise_matrix(ms->matrix, 1, 0);
	angle_matrix(t_mlxs *ms, Z, 0.785398);
	angle_matrix(t_mlxs *ms, X, 0.955323);
	/*
	*	35,264°
	*	0.6154729
	*	
	*	80,264°
	*	1.400871
	*
	*	155,264°
	*	2.709868
	*
		iso: 45° z-axis (0.785398 RAD)
			 54,736° x-axis (0.955323 RAD)
	*/
//	ms->mlx = NULL;
//	ms->win = NULL;
//	ms->cart = NULL;
//	ms->img1->img = NULL;
}

void	draw_map(t_mlxs *ms)
{
	t_line	line;
	int		x;
	int		y;

	x = 0;
	while (x < ms->row)
	{
		y = 0;
		while (y < ms->col)
		{
			if (ms->cart[x][y].color)
				(*ms->fad)->color = ms->cart[x][y].color;
			else
				(*ms->fad)->color = 0xFFFFFFFF;
			(*ms->fad)->color = see_color(ms, (*ms->fad)->color);
			if ((x + 1) != ms->row)
				draw_line(ms, ms->cart[x][y], ms->cart[x + 1][y], &line);
			if ((y + 1) != ms->col)
				draw_line(ms, ms->cart[x][y], ms->cart[x][y + 1], &line);
			y++;
		}
		x++;
	}
}

void	draw_line(t_mlxs *ms, t_coord ini, t_coord fin, t_line *l)
{
	l->x0 = ini.xyz[X];
	l->x1 = fin.xyz[X];
	l->y0 = ini.xyz[Y];
	l->y1 = fin.xyz[Y];
//	apply_matrix(ms, l);
	put_line(ms, l);
	//ft_printf("Draw Row x0: %i, x1: %i, y0: %i, y1:%i\n", l->x0, l->x1, l->y0, l->y1);
}

void	mlx_setup(t_mlxs *ms)
{
	ms->mlx = mlx_init();
	ms->win = mlx_new_window(ms->mlx, WIN_W, WIN_H, "FDF");
	(*ms->fad)->img = mlx_new_image(ms->mlx, WIN_W, WIN_H);
	(*ms->fad)->addr = mlx_get_data_addr\
	((*ms->fad)->img, &(*ms->fad)->bits_per_pixel, \
	&(*ms->fad)->line_length, &(*ms->fad)->endian);
	mlx_hook(ms->win, 17, 0, &close_win, ms);
	mlx_hook(ms->win, 2, 1L<<0, keypress, ms);
	mlx_mouse_hook(ms->win, mouse_group, ms);
	draw_map(ms);
	mlx_put_image_to_window(ms->mlx, ms->win, (*ms->fad)->img, WIN_W / 3, WIN_H /3);
	mlx_loop(ms->mlx);
}

int	see_color(t_mlxs *ms, int color)
{
	if (ms->toggle == 42)
		return (color);
	return (ms->color);
}


/*
pythtutor

#include <stdio.h>
void  id_matrix(int matrix[4][4]);
void  mult_matrix(int m1[4][4], int m2[4][4], int size);

int main(void)
{
  int matrix1[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
  static int matrix2[4][4];
  
  id_matrix(matrix2);
  mult_matrix(matrix1, matrix2, 4);
  for (int i = 0;i < 4; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      printf("%i\n", matrix1[i][j]);
    }
  }
  return 0;
}

void    id_matrix(int matrix[4][4])
{
    matrix[0][0] = 1;
    matrix[1][1] = 1;
    matrix[2][2] = 1;
    matrix[3][3] = 1;
}

void    mult_matrix(int m1[4][4], int m2[4][4], int size)
{
    int    prod[4][4];
    int        i;
    int        j;

    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < 4)
        {
            prod[i][j] = m1[i][0] * m2[0][j] +\
                        m1[i][1] * m2[1][j] +\
                        m1[i][2] * m2[2][j] +\
                        m1[i][3] * m2[3][j];
            j++;
        }
    i++;
    }
}

*/
