void	apply_matrix(t_mlxs *ms)
{
	ms->scale *= 1;
	return ;		
}


void	printma(int	matrix[4][4])
{
	for (int i = 0;i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
			ft_printf("%i\n", matrix[i][j]);
	}
}

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


//trying mouse functions


int		mousemove(int x, int y, t_mlxs *ms)
{
	ft_printf("moooving x: %i y: %i\n", x, y);
	mlx_hook(ms->win, 5, 1L<<3, mouserelease, ms);
	mlx_loop(ms->win);
	return (ms->row);
}

int		mouserelease(int keycode, int x, int y, t_mlxs *ms)
{
	ft_printf("bass dropped:");
	ft_printf("k: %i x: %i y: %i\n", keycode, x, y);
	return (ms->col);
}


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


	mlx_hook(ms->win, 5, 1L<<3, mouserelease, ms);
	int	mlx_mouse_move(void *mlx_ptr, void *win_ptr, int x, int y);
	mlx_hook(ms->win, 6, 1L<<6, mousemove, ms);

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



/**\
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
\**/



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


//colorrz

/*
#include <stdio.h>


void increase_color(int *red, int *green, int *blue, int factor)
{
	if (*red)
		*red += factor;
	if (*red > 255)
		*red = 255;
	if (*green)
		*green += factor;
	if (*green > 255)
		*green = 255;
	if (*blue)
		*blue += factor;
	if (*blue > 255)
		*blue = 255;
}

void decrease_color(int *red, int *green, int *blue, int factor)
{
	if (*red)
		*red -= factor;
	if (*red < 0)
		*red = 0;
	if (*green)
		*green -= factor;
	if (*green < 0)
		*green = 0;
	if (*blue)
		*blue -= factor;
	if (*blue < 0)
		*blue = 0;
}

int		change_color(int color, int factor, int sign)
{
	int red;
	int green;
	int blue;

	red = color & 0x00FF0000 >> 16;
	green = color & 0x0000FF00 >> 8;
	blue = color & 0x000000FF;
	if (sign < 0)
		decrease_color(&red, &green, &blue, factor);
	else
		increase_color(&red, &green, &blue, factor);
	printf("red: %i\ngreen: %i\nblue: %i\n", red, green, blue);
	return ((red << 16) + (green << 8) + blue);
}

int	badatoi(char *str)
{
	int i;
	int recoil;
	int	base;

	i = 0;
	base = 1;
	recoil = 0;
	while (str[i])
		i++;
	while (--i >= 0)
	{
		recoil += (str[i] - '0') * base;
		base *= 10;
	}
	return (recoil);
}

int main(int argc, char **argv)
{
	int	n;
	int	color;

	color = 0x00FFFFFF;
	if (argc != 2)
		return (1);
	n = badatoi(argv[1]);
	printf("%i\n0x%X\n", n, change_color(color, 3, 1));
}


// not used
void increase_color(int *red, int *green, int *blue, int factor)
{
	if (*red)
		*red += factor;
	if (*red > 255)
		*red = 255;
	if (*green)
		*green += factor;
	if (*green > 255)
		*green = 255;
	if (*blue)
		*blue += factor;
	if (*blue > 255)
		*blue = 255;
}

void	decrease_color(int *red, int *green, int *blue, int factor)
{
	if (*red)
		*red -= factor;
	if (*red < 0)
		*red = 0;
	if (*green)
		*green -= factor;
	if (*green < 0)
		*green = 0;
	if (*blue)
		*blue -= factor;
	if (*blue < 0)
		*blue = 0;
}

void	change_color(t_mlxs *ms, int factor, int sign)
{
	int red;
	int green;
	int blue;

	red = ms->dye & 0x00FF0000 >> 16;
	green = ms->dye & 0x0000FF00 >> 8;
	blue = ms->dye & 0x000000FF;
	if (sign < 0)
		decrease_color(&red, &green, &blue, factor);
	else
		increase_color(&red, &green, &blue, factor);
	ms->dye = (red << 16) + (green << 8) + blue;
}
*/

