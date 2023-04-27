#include "push_swap.h"

static int	split_stack(t_ctrl *c, int pivot)
{
	if (c->size_b < 2)
	{
		if (c->head_a->i < pivot)
			return (push_b(c));
		else
			return (rotate_a(c));
	}
	if (c->head_a->i < pivot)
		return (push_b(c));
	else if (c->head_b->i < c->head_b->next->i)
		return (rotate_both(c));
	else
		return (rotate_a(c));
}

int	sort_stack(t_ctrl *c, int quadrant, int size)
{
	int	pivot;

	pivot = (size * quadrant) / 4;
	ft_printf("Final pivot: %i and size %i\n", pivot, size);
	while (c->size_b < size / 2)
	{
		split_stack(c, size / 2);
		print_stacks(c);
	}
	return (pivot);
}
