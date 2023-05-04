#include "push_swap.h"

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

int	sort_three_b(t_item *item, int *sol)
{
	int	a;
	int	b;
	int	c;

	a = item->i;
	b = item->next->i;
	c = item->next->next->i;
	if (a > b && b > c && a > c)
		return (0);
	if (a < b && b > c && a > c)
		*sol = SB;
	if (a < b && b > c && a < c)
		*sol = RB;
	if (*sol)
		return (1);
	if (a < b && b < c)
		*sol = RB;
	if (a > b && b < c)
		*sol = RRB;
	if (a > b && a < c)
		return (1);
	sol++;
	*sol = SB;
	return (2);
}

void	back_to_a(t_ctrl *c)
{
	int	target;
	int	spot;

	target = c->head_b->i + 1;
	spot = find_target(c->head_a, target);
	if (spot < 0)
	{
		c->b_stream = trace_move(push_a(c), c->b_stream, c);
		c->a_stream = trace_move(rotate_a(c), c->a_stream, c);
		return ;
	}
	while (c->head_a->i != target)
	{
		if (spot > c->size_a / 2)
			c->a_stream = trace_move(rev_rotate_a(c), c->a_stream, c);
		else
			c->a_stream = trace_move(rotate_a(c), c->a_stream, c);
	}
	c->b_stream = trace_move(push_a(c), c->b_stream, c);
}
/*
int find_highest(t_item *head) 
{
	int highest;
	t_item *item;

	highest = head->i;
	item = head->next;
	while (item)
	{
		if (item->i > highest)
			highest = item->i;
		item = item->next;
	}
	return (highest);
}

void back_to_a(t_ctrl *c) 
{
	int target;
	int spot;

	target = find_highest(c->head_b);
	spot = find_target(c->head_a, target);
	while (c->head_b->i != target)
		c->b_stream = trace_move(rev_rotate_b(c), c->b_stream, c);
	while (c->head_a->i != spot)
	{
		if (find_target(c->head_a, target) > c->size_a / 2)
			c->a_stream = trace_move(rev_rotate_a(c), c->a_stream, c);
		else
			c->a_stream = trace_move(rotate_a(c), c->a_stream, c);
	}
	c->b_stream = trace_move(push_a(c), c->b_stream, c);
}
*/
void	solve_small(t_ctrl *c, int *sol)
{
	if (c->size_a == 2)
	{
		set_array(sol, 2);
		sol[0] = SA;
	}
	else
	{
		while (c->size_a > 3)
			c->a_stream = trace_move(push_b(c), c->a_stream, c);
		set_array(sol, 3);
		sort_three_a(c->head_a, sol);
	}
	array_sol(c->a_stream, sol, c);
	c->a_stream = apply_sol(c->a_stream, c);
	if (c->size_b > 2)
	{
		set_array(sol, 2);
		sort_three_b(c->head_b, sol);
		array_sol(c->b_stream, sol, c);
		c->b_stream = apply_sol(c->b_stream, c);
	}
	print_full_stacks(c);
/*	print_sol(c->sol_a);
	write(1, "pog\n", 4);
	print_sol(c->sol_b);
	write(1, "pog\n", 4);*/
	while (c->size_b)
		back_to_a(c);
	while (!is_sorted(c))
		c->a_stream = trace_move(rev_rotate_a(c), c->a_stream, c);
}