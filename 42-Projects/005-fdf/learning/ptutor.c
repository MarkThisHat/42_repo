#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_coord {

int				z;
int				color;

}				t_coord;

typedef struct	s_mlxs {
t_coord			**xy;
int				col;
int				row;
}				t_mlxs;

void	foo(t_mlxs* ms);

int	main(void)
{
	t_mlxs	ms;

	ms.row = 4;
	ms.col = 3;    
	foo(&ms);
	return (0);
}

void	foo(t_mlxs* ms)
{
	int	i = 0;
	int	j;

	ms->xy = malloc(sizeof(t_coord *) * (ms->row));
	while (i < ms->row)
	{
		ms->xy[i] = malloc(sizeof(t_coord) * ms->col);
		j = 0;
		while (j < ms->col)
		{
			ms->xy[i][j].z = i;
			ms->xy[i][j].color = j;
			j++;
		}
		i++;
	}
}
