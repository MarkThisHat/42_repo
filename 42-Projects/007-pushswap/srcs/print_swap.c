#include "push_swap.h"

static void	put_move(int move)
{
		if (move == SA)
			write(1, "sa\n", 3);
		else if (move == SB)
			write(1, "sb\n", 3);
		else if (move == SS)
			write(1, "ss\n", 3);
		else if (move == PA)
			write(1, "pa\n", 3);
		else if (move == PB)
			write(1, "pb\n", 3);
		else if (move == RA)
			write(1, "ra\n", 3);
		else if (move == RB)
			write(1, "rb\n", 3);
		else if (move == RR)
			write(1, "rr\n", 3);
		else if (move == RRA)
			write(1, "rra\n", 4);
		else if (move == RRB)
			write(1, "rrb\n", 4);
		else if (move == RRR)
			write(1, "rrr\n", 4);
}

void	print_sol(t_sol *s)
{
	if (!s)
		return ;
	put_move(s->move);
	print_sol(s->next);
}
