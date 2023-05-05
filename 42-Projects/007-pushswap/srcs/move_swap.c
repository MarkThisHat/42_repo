#include "push_swap.h"

int	do_move(t_ctrl *c, int move)
{
	if (move == SA)
		return(swap_a(c));
	if (move == SB)
		return(swap_b(c));
	if (move == SS)
		return(swap_both(c));
	if (move == PA)
		return(push_a(c));
	if (move == PB)
		return(push_b(c));
	if (move == RA)
		return(rotate_a(c));
	if (move == RB)
		return(rotate_b(c));
	if (move == RR)
		return(rotate_both(c));
	if (move == RRA)
		return(rev_rotate_a(c));
	if (move == RRB)
		return(rev_rotate_b(c));
	if (move == RRR)
		return(rev_rotate_both(c));
	return (0);
}

int	dive_target(t_item *stack, int target)
{
	int	i;

	i = 1;
	while (stack)
	{
		if (stack->i == target)
			return (i);
		stack = stack->next;
		i++;
	}
	return (0);
}

int	climb_target(t_item *stack, int target)
{
	int	i;

	i = 1;
	while (stack)
	{
		if (stack->i == target)
			return (i);
		stack = stack->prev;
		i++;
	}
	return (0);
}
