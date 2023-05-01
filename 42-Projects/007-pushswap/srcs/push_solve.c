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

void	fill_sol(int *sol, int size)
{
	sol[--size] = -1;
	while (size-- + 1)
		sol[size] = 0;
}

t_sol	*apply_sol(t_sol *s, t_ctrl *c)
{
	t_sol	*latest;
	
	while (s)
	{
		if (s->move == SA)
			swap_a(c);
		if (s->move == SB)
			swap_b(c);
		if (s->move == PA)
			push_a(c);
		if (s->move == PB)
			push_b(c);
		if (s->move == RA)
			rotate_a(c);
		if (s->move == RB)
			rotate_b(c);
		if (s->move == RRA)
			rev_rotate_a(c);
		if (s->move == RRB)
			rev_rotate_b(c);
		latest = s;
		s = s->next;
	}
	return (latest);
}

int		weave_sol(t_sol *s, int *sol)
{
	while (*sol > 0)
	{
		s->move = *sol;
		s->next = malloc(sizeof(t_sol));
		if (!s->next)
			return (0);
		*s->next = (t_sol){0};
		s = s->next;
		sol++;
	}
	return (1);
}

t_sol	*set_solution(t_sol *s)
{
	while (s && s->next)
		s = s->next;
	s = malloc(sizeof(t_sol));
	if (!s)
		return (NULL);
	*s = (t_sol){0};
	return (s);
}

void	find_sol(t_ctrl *c)
{
	int		sol[3];

	c->sol_a = set_solution(c->sol_a);
	if (!c->sol_a)
		free_and_leave(c, 4);
	if (c->size_a == 2)
	{
		fill_sol(sol, 2);
		sol[0] = SA;
	}
	else
	{
		while (c->size_a > 3)
			push_b(c);
		fill_sol(sol, 3);
		sort_three(c->head_a, sol);
	}
	if (!weave_sol(c->sol_a, sol))
		free_and_leave(c, 4);
	apply_sol(c->sol_a, c);
}
/*
t_sol	*log_and_act(int move, t_sol *stack)
{
	stack->move = move;
	stack->next = malloc(sizeof(t_sol));
}*/

/*
int	sort_five(t_ctrl *c, int size)
{
	int	sol[2];
	
	while(size-- > 3)
		push_b(c);
	sol[0] = 0;
	sol[1] = 0;
	sort_three(c->head_a, sol);
	return (0);
}
*/