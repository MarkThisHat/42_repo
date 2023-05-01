#include "push_swap.h"

int	sort_three(t_item *item, int *sol)
{
	int	a;
	int	b;
	int	c;

	a = item->i;
	b = item->next->i;
	c = item->next->next->i;
	if (a < b && b < c && a < c)
		return (0);
	if (a > b && b < c && a < c)
		*sol = SA;
	if (a > b && b < c && a > c)
		*sol = RA;
	if (*sol)
		return (1);
	if (a > b && b > c)
		*sol = RA;
	if (a < b && b > c)
		*sol = RRA;
	if (a < b && a > c)
		return (1);
	sol++;
	*sol = SA;
	return (2);
}

void	find_sol(t_ctrl *c)
{
	int		sol[3];
	t_sol	*stream;

	c->sol_a = prep_sol(c->sol_a);
	if (!c->sol_a)
		free_and_leave(c, 4);
	stream = c->sol_a;
	if (c->size_a == 2)
	{
		set_array(sol, 2);
		sol[0] = SA;
	}
	else
	{
		while (c->size_a > 3)
			stream = trace_move(push_b(c), stream, c);
		set_array(sol, 3);
		sort_three(c->head_a, sol);
	}
	if (!array_sol(stream, sol))
		free_and_leave(c, 4);
	apply_sol(stream, c);
	print_sol(c->sol_a);
}
