#include "push_swap.h"

t_sol	*prep_sol(t_sol *s)
{
	s = malloc(sizeof(t_sol));
	if (!s)
		return (NULL);
	*s = (t_sol){0};
	return (s);
}

t_sol	*log_move(int move, t_sol *stack, t_ctrl *c)
{
//	print_stacks(c);
	stack->next = prep_sol(stack->next);
	if (!stack->next)
		free_and_leave(c, 4);
	stack->next->move = move;
	return (stack->next);
}

t_sol	*get_stream(t_sol *s)
{
	if (s->next)
		return (get_stream(s->next));
	return (s);
}
