#include "push_swap.h"

static t_sol	*first_move_small(t_ctrl *c)
{
	t_sol	*list;

	if (c->size_a == 2)
	{
		write(1, "sa\n", 3);
		free_and_leave(c, 0);
	}
	list = malloc(sizeof(t_sol));
	if (!list)
		free_and_leave(c, 4);
	*list = (t_sol){0};
	return (list);
}

void	find_sol(t_ctrl *c)
{
	if (c->size_a <= 5)
		c->answer = first_move_small(c);
	if (c->size_a == 3)
		a_is_three(c, c->answer);
	else if (c->size_a <= 5)
		c->answer->move = push_b(c);
	if (c->size_a < 5 && c->size_b)
		small_sol(c, c->size_a + c->size_b);
	else
	 	big_sol(c, c->size_a + c->size_b);
/*	ft_printf("pre-optimization\n");
	print_sol(c->answer);
	ft_printf("aftermath\n");*/
	optimize_solution(c->answer, c->answer);
	print_sol(c->answer);
//	print_stacks(c);
//	ft_printf("aftermath\n");
	reset_stacks(c, c->answer);
//	print_stacks(c);
}