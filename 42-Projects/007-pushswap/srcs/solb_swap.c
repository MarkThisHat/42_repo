#include "push_swap.h"

int	find_climb_chunk(int size)//, int pivot)
{
	static int	i;

	i++;
	if (i < optimal_partitioning(size))
		return ((size * i) / optimal_partitioning(size));
	else
		return (size);
//	(void)pivot;
}

void	set_bigger_b(t_item *item, int *smaller, int *bigger)
{
	*smaller = item->i;
	while (item)
	{
		if (item->i > *bigger)
			*bigger = item->i;
		if (item->i < *smaller)
			*smaller = item->i;
		item = item->next;
	}
}

int	take_in_b(t_ctrl *c, int aim)
{
	static int	bigger;
	static int	smaller;
//ft_printf("Aim: %i\nBigger: %i\nSmaller: %i\n", aim, bigger, smaller);
	if (c->size_b < 3)
		return (0);
	if (!bigger && !smaller)
		set_bigger_b(c->head_b, &smaller, &bigger);
	if (c->size_b == 3)
		sort_three(c, c->head_b, 1);
	if (aim > bigger)
		bigger = aim;
	if (aim < smaller)
		smaller = aim;
	if (aim == bigger || aim == smaller)
		c->stream = log_move(push_b(c), c->stream, c);
	if (aim == smaller)
		c->stream = log_move(rotate_b(c), c->stream, c);
	if (aim == bigger || aim == smaller)
		return (1);
	while (c->head_b->i > aim)
		c->stream = log_move(rotate_b(c), c->stream, c);
	c->stream = log_move(push_b(c), c->stream, c);
	while (c->head_b->i != bigger)
		c->stream = log_move(rev_rotate_b(c), c->stream, c);
	return (1);
}

void	pogo_sol(t_ctrl *c, int size)
{
	int	max;
	int	pivot;
	int	aim;

	pivot = 0;
	max = find_climb_chunk(size);
	if (c->head_a->i >= pivot && c->head_a->i <= max)
		c->answer = first_move_big(c, PB);
	else
		c->answer = first_move_big(c, RA);
	c->stream = get_stream(c->answer);
//	print_full_stacks(c);
//	ft_printf("First pivot and max are %i and %i\n", pivot, max);
	while (c->size_a)// > 3 && max)
	{
		aim = has_amidst(c->head_a, pivot, max);
		if (aim >= 0)
		{
			if (climb_target(c->tail_a, aim) > dive_target(c->head_a, aim))
				while (c->head_a->i != aim)
					c->stream = log_move(rotate_a(c), c->stream, c);
			else
				while (c->head_a->i != aim)
					c->stream = log_move(rev_rotate_a(c), c->stream, c);
			if (!take_in_b(c, aim))
				c->stream = log_move(push_b(c), c->stream, c);
		}
		else
		{
			pivot = max + 1;
			max = find_climb_chunk(size);
//			ft_printf("Pivot and max are %i and %i\n", pivot, max);
		}
//		print_full_stacks(c);
	}
	while (c->size_b)
		c->stream = log_move(push_a(c), c->stream, c);
//	print_full_stacks(c);
}
