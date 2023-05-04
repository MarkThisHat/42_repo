#include "push_swap.h"

t_sol	*prep_sol(t_sol *s)
{
	s = malloc(sizeof(t_sol));
	if (!s)
		return (NULL);
	*s = (t_sol){0};
	return (s);
}

void	a_is_three(t_ctrl *c, t_sol *sol)
{
	int	x;
	int	y;
	int	z;

	x = c->head_a->i;
	y = c->head_a->next->i;
	z = c->head_a->next->next->i;
	if (x > y && y < z && x < z)
		sol->move = swap_a(c);
	if (x > y && y < z && x > z)
		sol->move = rotate_a(c);
	if (x > y && y > z)
		sol->move = rotate_a(c);
	if (x < y && y > z)
		sol->move = rev_rotate_a(c);
	if (is_sorted(c))
		return ;
	sol->next = prep_sol(sol);
	if (!sol->next)
		free_and_leave(c, 4);
	sol->next->move = swap_a(c);
}
