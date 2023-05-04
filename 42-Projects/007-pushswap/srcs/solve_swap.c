#include "push_swap.h"

static t_sol	*first_move(t_ctrl *c)
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

void	find_sol(t_ctrl *c)
{
	c->answer = first_move(c);
	if (c->size_a == 3)
		a_is_three(c, c->answer);
	else
		c->answer->move = push_b(c);
	if (c->size_a < 6)
		small_sol(c);
//	else
//		big_sol(c);
	print_sol(c->answer);
	print_sol(c->stream);
}