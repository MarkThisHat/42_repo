#include "push_swap.h"

static void	exec_undo_move(t_ctrl *c, int move)
{
		if (move == SA)
			swap_a(c);
		else if (move == SB)
			swap_b(c);
		else if (move == SS)
			swap_both(c);
		else if (move == PB)
			push_a(c);
		else if (move == PA)
			push_b(c);
		else if (move == RRA)
			rotate_a(c);
		else if (move == RRB)
			rotate_b(c);
		else if (move == RRR)
			rotate_both(c);
		else if (move == RA)
			rev_rotate_a(c);
		else if (move == RB)
			rev_rotate_b(c);
		else if (move == RR)
			rev_rotate_both(c);
}

void	reset_stacks(t_ctrl *c, t_sol *solution)
{
	if (!solution)
		return ;
	reset_stacks(c, solution->next);
	exec_undo_move(c, solution->move);
}
