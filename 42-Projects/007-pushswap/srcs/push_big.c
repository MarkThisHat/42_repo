/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:04:51 by maalexan          #+#    #+#             */
/*   Updated: 2023/05/09 10:59:21 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	smart_repile_a(t_ctrl *c, int target)
{
	int	climb;
	int	dive;

	climb = climb_target(c->tail_b, target);
	dive = dive_target(c->head_b, target);
//	ft_printf("Target is %i climb target is %i, dive target is %i\n", target, climb, dive);
	if (climb > dive)
		while (c->head_b->i != target)
			c->stream = log_move(rotate_b(c), c->stream, c);
	else
		while (c->head_b->i != target)
			c->stream = log_move(rev_rotate_b(c), c->stream, c);
	c->stream = log_move(push_a(c), c->stream, c);
}

void	sol_s(t_ctrl *c, int size)
{
	int	i;
	int	pivot;

	pivot = size / 2;
	if (c->head_a->i < pivot)
		c->answer = first_move_big(c, PB);
	else
		c->answer = first_move_big(c, RA);
	c->stream = get_stream(c->answer);
//	print_stacks(c);
	while (c->size_b < size / 2)
	{
		if (c->head_a->i < pivot)
			c->stream = log_move(push_b(c), c->stream, c);
		else
			c->stream = log_move(rotate_a(c), c->stream, c);
	}
//	print_stacks(c);
	i = pivot;
	while (i)
		smart_repile_a(c, --i);
//	print_stacks(c);
	while (c->size_a)
		c->stream = log_move(push_b(c), c->stream, c);
//	print_stacks(c);
	i = size;
	while (i)
		smart_repile_a(c, --i);
//	print_stacks(c);
}

int	optimal_partitioning(int size)
{
	if (size < 101)
		return (5);
	else
		return (11);
}

int	find_chunk(int size, int pivot)
{
	static int	i;

	if (pivot == size)
		i = optimal_partitioning(size);
	i--;
	return ((size * i) / optimal_partitioning(size));
}

int	has_lull(t_item *stack, int start, int end)
{
	while (stack)
	{
		if (stack->i >= start && stack->i <= end)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	move_to_b(t_ctrl *c, int pivot, int max, int first_call)
{
//	int	size;

	if (first_call)
	{
		if (c->head_a->i > pivot && c->head_a->i < max)
				c->answer = first_move_big(c, PB);
			else
				c->answer = first_move_big(c, RA);
		c->stream = get_stream(c->answer);
	}
//	size = max;
//	ft_printf("Should be passing >= %i and <= %i, cycling %i\n", pivot, max, size);
	while (has_lull(c->head_a, pivot, max))
		if (c->head_a->i >= pivot && c->head_a->i <= max)
			c->stream = log_move(push_b(c), c->stream, c);
		else
			c->stream = log_move(rotate_a(c), c->stream, c);
}

void	resort_a(t_ctrl *c, int pivot, int max)
{
	if (max == c->size_a + c->size_b)
		max--;
	while (max >= pivot)
	{
		smart_repile_a(c, max);
		max--;
	}
}

void	sol_a(t_ctrl *c, int size)
{
	int	pivot;
	int max;
	
//	ft_printf("Pog: %i\n", c->size_a + c->size_b);
	pivot = find_chunk(size, size);
	max = size;
	move_to_b(c, pivot, max, 1);
//	print_full_stacks(c);
	while (pivot)
	{
//		print_stacks(c);
		resort_a(c, pivot, max);
		max = pivot - 1;
		pivot = find_chunk(size, pivot);
		move_to_b(c, pivot, max, 0);
	}
	resort_a(c, pivot, max);
//	print_full_stacks(c);
}

void	big_sol(t_ctrl *c, int size)
{
	//sol_s(c, size);
	sol_a(c, size);
}