#include "push_swap.h"


static void	sort_the_odd(t_ctrl *c, t_item *item)
{
	int	trouble;

	trouble = item->i;
	ft_printf("Index you have to deal with: %i next: %i\n", item->i, item->next->i);
	if (climb_target(c->tail_a, trouble) >= dive_target(c->head_a, trouble))
		while(c->head_a->i != trouble)
			c->stream = log_move(rotate_a(c), c->stream, c);
	else
		while(c->head_a->i != trouble)
			c->stream = log_move(rev_rotate_a(c), c->stream, c);
	print_full_stacks(c);
	exit(43);
}

void	fix_unsorted_element(t_ctrl *c)
{
	t_item	*unsorted;

	unsorted = c->head_a;
	while (unsorted->next)
		if (unsorted->i + 1 != unsorted->next->i)
			sort_the_odd(c, unsorted->next);
		else
			unsorted = unsorted->next;
}