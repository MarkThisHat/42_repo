#include "push_swap.h"

t_sol	*apply_sol(t_sol *s, t_ctrl *c)
{
	t_sol	*stream;
	
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
		stream = s;
		s = s->next;
	}
	return (stream);
}

t_sol	*prep_sol(t_sol *s)
{
	while (s && s->next)
		s = s->next;
	s = malloc(sizeof(t_sol));
	if (!s)
		return (NULL);
	*s = (t_sol){0};
	return (s);
}

t_sol	*trace_move(int move, t_sol *stack, t_ctrl *c)
{
	stack->move = move;
	stack->next = prep_sol(stack->next);
	if (!stack->next)
		free_and_leave(c, 4);
	return (stack->next);
}

void	set_array(int *sol, int size)
{
	sol[--size] = -1;
	while (size-- + 1)
		sol[size] = 0;
}

int		array_sol(t_sol *s, int *sol)
{
	while (*sol > 0)
	{
		s->move = *sol;
		s->next = prep_sol(s);
		if (!s->next)
			return (0);
		s = s->next;
		sol++;
	}
	return (1);
}