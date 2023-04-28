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

	ft_printf("Idx A %i\n", measure_index(c->head_a, c->size_a, 0));
	(void)quadrant;
	pivot = size / 2;
	ft_printf("Final pivot: %i and size %i\n", pivot, size);
	while (c->size_b < pivot)
	{
		split_stack(c, pivot);
		print_full_stacks(c);
	}
	ft_printf("Idx A %i\n", measure_index(c->head_a, c->size_a, pivot));
	ft_printf("Idx B %i\n", measure_index(c->head_b, c->size_b, 0));
	return (pivot);
}
