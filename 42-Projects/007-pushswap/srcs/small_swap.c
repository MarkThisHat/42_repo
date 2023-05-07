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

static void	four_or_five(t_ctrl *c, int size)
{
	int	target;

	if (c->head_b->i < size / 2 + 1)
		while (c->head_a->i != c->head_b->i + 1)
			c->stream = log_move(rotate_a(c), c->stream, c);
	else
		while (c->head_a->i != c->head_b->i + 1)
			c->stream = log_move(rev_rotate_a(c), c->stream, c);
	c->stream = log_move(push_a(c), c->stream, c);
	if (c->head_b)
	{
		target = dive_target(c->head_a, c->head_b->i + 1);
		if (target < size / 2 + 1)
			while (c->head_a->i != c->head_b->i + 1)
				c->stream = log_move(rotate_a(c), c->stream, c);
		else
			while (c->head_a->i != c->head_b->i + 1)
				c->stream = log_move(rev_rotate_a(c), c->stream, c);
		c->stream = log_move(push_a(c), c->stream, c);
	}
}

void	small_sol(t_ctrl *c, int size)
{
	c->stream = get_stream(c->answer);
	while (c->size_a > 3)
		c->stream = log_move(push_b(c), c->stream, c);
	sort_three(c, c->head_a, 0);
	if (size == 5 && c->head_b->i < c->head_b->next->i)
		c->stream = log_move(swap_b(c), c->stream, c);
	if (c->head_b->i == size - 1)
	{
		c->stream = log_move(push_a(c), c->stream, c);
		c->stream = log_move(rotate_a(c), c->stream, c);
	}
	if (c->head_b && !c->head_b->i)
		c->stream = log_move(push_a(c), c->stream, c);
	if (c->head_b)
		four_or_five(c, size);
	ft_printf("%i dive target\n", dive_target(c->head_a, 0));
	print_stacks(c);
	if (dive_target(c->head_a, 0) > (size / 2 + 1))
		while (c->head_a->i)
			c->stream = log_move(rev_rotate_a(c), c->stream, c);
	else
		while (c->head_a->i)
			c->stream = log_move(rotate_a(c), c->stream, c);
}
