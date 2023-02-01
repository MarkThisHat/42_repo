#include "../incl/fdf.h"

int		keypress(int keycode, t_mlxs *ms)
{
	if (keycode == ESC_K)
		close_win(ms);
	return (keycode);
}

int		close_win(t_mlxs *ms)
{
	mlx_destroy_image(ms->mlx, ms->img1->img);
	mlx_destroy_window(ms->mlx, ms->win);
	mlx_destroy_display(ms->mlx);
	free(ms->mlx);
	free_close(ms, 0, ms->row);
	return (1);	
}

void	free_close(t_mlxs *ms, char *str, int rows)
{
	while(rows)
	{
		rows--;
		free(ms->xy[rows]);
	}
	if(ms->xy)
		free(ms->xy);
	if (!str)
		leave_program(0, 0, 0);
	leave_program(str, 2, 5);
}

void	leave_program(char *str, int fd, int return_code)
{
	if (return_code == 0)
		exit (0);
	ft_putstr_fd(str, fd);
	exit (return_code);
}
