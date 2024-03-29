#include "push_swap.h"

void	make_move(t_ctrl *c, int move)
{
	if (move == SA)
		swap_a(c);
	if (move == SB)
		swap_b(c);
	if (move == SS)
		swap_both(c);
	if (move == PA)
		push_a(c);
	if (move == PB)
		push_b(c);
	if (move == RA)
		rotate_a(c);
	if (move == RB)
		rotate_b(c);
	if (move == RR)
		rotate_both(c);
	if (move == RRA)
		rev_rotate_a(c);
	if (move == RRB)
		rev_rotate_b(c);
	if (move == RRR)
		rev_rotate_both(c);
}

t_sol	*apply_sol(t_sol *s, t_ctrl *c)
{
	t_sol	*stream;
	
	while (s)
	{
		make_move(c, s->move);
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

void	array_sol(t_sol *s, int *sol, t_ctrl *c)
{
	while (*sol > 0)
	{
		s->move = *sol;
		s->next = prep_sol(s);
		if (!s->next)
			free_and_leave(c, 0);
		s = s->next;
		sol++;
	}
}

/*
void	array_sol(t_ctrl *c, int *sol, char pile)
{
	t_sol	*s;

	if (pile == 'a')
		s = c->a_stream;
	if (pile == 'b')
		s = c->b_stream;
	while (*sol > 0)
	{
		s->move = *sol;
		s->next = prep_sol(s);
		if (!s->next)
			free_and_leave(c, 0);
		s = s->next;
		sol++;
	}
	if (pile == 'a')
		c->a_stream = s;
	if (pile == 'b')
		c->b_stream = s;
}

void array_sol(t_ctrl *c, int *sol, char pile)
{
	t_sol **s_ptr;

	if (pile == 'a')
		s_ptr = &(c->a_stream);
	else if (pile == 'b')
		s_ptr = &(c->b_stream);
	else
		return;
	while (*sol > 0)
	{
		(*s_ptr)->move = *sol;
		(*s_ptr)->next = prep_sol(*s_ptr);
		if (!(*s_ptr)->next)
			free_and_leave(c, 0);
		*s_ptr = (*s_ptr)->next;
		sol++;
	}
}
*/