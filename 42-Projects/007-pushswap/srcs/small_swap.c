#include "push_swap.h"

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

void	sort_three(t_ctrl *c, t_item *head, int is_b)
{
	int	x;
	int	y;
	int	z;
	int	sign;

	sign = 1;
	if (is_b)
		sign = -1;
	x = head->i * sign;
	y = head->next->i * sign;
	z = head->next->next->i * sign;
	if (x < y && y < z)
		return ;
	if (x > y && y < z && x < z)
		c->stream = log_move(do_move(c, SA + is_b), c->stream, c);
	if (x > y && y < z && x > z)
		c->stream = log_move(do_move(c, RA + is_b), c->stream, c);
	if (x > y && y > z)
		c->stream = log_move(do_move(c, RA + is_b), c->stream, c);
	if (x < y && y > z)
		c->stream = log_move(do_move(c, RRA + is_b), c->stream, c);
	if ((x > y && y > z) || (x < y && y > z && x < z))
		c->stream = log_move(do_move(c, SA + is_b), c->stream, c);
}

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

void	small_sol(t_ctrl *c)
{
	c->stream = get_stream(c->answer);
	while (c->size_a > 3)
		c->stream = log_move(push_b(c), c->stream, c);
	print_stacks(c);
	sort_three(c, c->head_a, 0);
	sort_three(c, c->head_b, 1);
}

/*
int	sort_three_a(t_item *item, int *sol)
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
*/