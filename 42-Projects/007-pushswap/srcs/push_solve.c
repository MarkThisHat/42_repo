#include "push_swap.h"

static int measure_index(t_item *pile, int size, int pivot)
{
	int *indices;
	int i;
	int total_distance;
	int	ideal_position;
	int	distance;

	indices = ft_calloc(size, sizeof(int));
	if (!indices)
		return (-1);
	i = 0;
	total_distance = 0;
	while (pile)
	{
		indices[i] = pile->i;
		pile = pile->next;
		i++;
	}
	for (i = 0; i < size; i++)
	{
		if (pivot)
			ideal_position = indices[i] - pivot; // Ideal position in the sorted pile
		else
			ideal_position = size -1 - indices[i];
		distance = ideal_position - i; // Distance from the ideal position
		if (distance < 0)
			distance = -distance;
		total_distance += distance;
	}
	free(indices);
	return (total_distance /size);
}

/*
static int	split_rotate(t_ctrl *c, int pivot)
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
*/

static int	split_swap(t_ctrl *c, int pivot)
{
	if (c->size_b < 2)
	{
		if	(c->size_a > 1 && c->head_a->i < c->head_a->next->i)
			return(swap_a(c));
		else if (c->head_a->i < pivot)
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
	int len;
	int	i;

	i = 0;
	len = size * 2;
	pivot = size / 2;
	ft_printf("Quadrant: %i\nPivot: %i\n", quadrant, pivot);
	while (len--)
	{
		split_swap(c, pivot);
		i++;
	}
	print_full_stacks(c);
	ft_printf("Idx A %i\n", measure_index(c->head_a, c->size_a, pivot));
	ft_printf("Idx B %i\n", measure_index(c->head_b, c->size_b, 0));
	ft_printf("%i moves\n", i);
	return (pivot);
}

int	sort_three(t_item *item, int *sol)
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

/*
1 1 2 2 3 3
2 3 1 3 1 2
3 2 3 1 2 1


1 2 2 3 3
3 1 3 1 2
2 3 1 2 1

1	//////swap_a->rotate_a//////
3	rev_rotate_a->swap_a
2
if (a < b && b > c)
if (a < c)

//moves not used
if (a < b && b > c && a < c)
swap_a->rotate_a;
if (a > b && b > c)
swap-a->rev_rotate_a

3	///swap_a->rev_rotate_a/////
2	rotate_a->swap_a
1
if (a > b && b > c)

2	rev_rotate_a
3
1
if (a < b && b > c)
a < b, , a > c







//
2	swap_a
1
3
if (a > b && b < c && a < c)


3	rotate_a
1
2
if (a > b && b < c && a > c)
