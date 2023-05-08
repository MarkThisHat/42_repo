#include "push_swap.h"

static	void	smart_repile_a(t_ctrl *c, int target)
{
	int	climb;
	int	dive;

	climb = climb_target(c->tail_b, target);
	dive = dive_target(c->head_b, target);
	if (climb > dive)
		while(c->head_b->i != target)
			c->stream = log_move(rotate_b(c), c->stream, c);
	else
		while(c->head_b->i != target)
			c->stream = log_move(rev_rotate_b(c), c->stream, c);
	c->stream = log_move(push_a(c), c->stream, c);
}

void	sol_s(t_ctrl *c, int size)
{
	int	i;
	int pivot;

	pivot = size / 2;
	if (c->head_a->i < pivot)
		c->answer = first_move_big(c, PB);
	else
		c->answer = first_move_big(c, RA);
	c->stream = get_stream(c->answer);
//	print_stacks(c);
	while (c->size_b < size / 2)
	{
		if (c->head_a->i < pivot)
			c->stream = log_move(push_b(c), c->stream, c);
		else
			c->stream = log_move(rotate_a(c), c->stream, c);
	}
//	print_stacks(c);
	i = pivot;
	while (i)
		smart_repile_a(c, --i);
//	print_stacks(c);
	while (c->size_a)
		c->stream = log_move(push_b(c), c->stream, c);
//	print_stacks(c);
	i = size;
	while (i)
		smart_repile_a(c, --i);
//	print_stacks(c);
}

void	big_sol(t_ctrl *c, int size)
{
	sol_s(c, size);
}