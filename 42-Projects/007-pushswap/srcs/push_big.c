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
	if (climb > dive)
		while (c->head_b->i != target)
			c->stream = log_move(rotate_b(c), c->stream, c);
	else
		while (c->head_b->i != target)
			c->stream = log_move(rev_rotate_b(c), c->stream, c);
	c->stream = log_move(push_a(c), c->stream, c);
}

int	find_dive_chunk(int size, int pivot)
{
	static int	i;

	if (pivot == size)
		i = optimal_partitioning(size);
	i--;
	return ((size * i) / optimal_partitioning(size));
}

void	move_to_b(t_ctrl *c, int pivot, int max, int first_call)
{
	int	i;

	i = 3;
	if (first_call)
	{
		if (c->head_a->i > pivot && c->head_a->i < max)
			c->answer = first_move_big(c, PB);
		else
			c->answer = first_move_big(c, RA);
		c->stream = get_stream(c->answer);
	}
	while (has_amidst(c->head_a, pivot, max) >= 0)
	{
		if (c->head_a->i >= pivot && c->head_a->i <= max)
			c->stream = log_move(push_b(c), c->stream, c);
		else
			c->stream = log_move(rotate_a(c), c->stream, c);
		i--;
	}
}

/*
void	move_to_b(t_ctrl *c, int pivot, int max, int first_call)
{
	if (first_call)
	{
		if (c->head_a->i > pivot && c->head_a->i < max)
			c->answer = first_move_big(c, PB);
		else
			c->answer = first_move_big(c, RA);
		c->stream = get_stream(c->answer);
	}
	while (has_amidst(c->head_a, pivot, max) >= 0)
		if (c->head_a->i >= pivot && c->head_a->i <= max)
			c->stream = log_move(push_b(c), c->stream, c);
		else
			c->stream = log_move(rotate_a(c), c->stream, c);
}
*/
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
	
	pivot = find_dive_chunk(size, size);
	max = size;
	move_to_b(c, pivot, max, 1);
	while (pivot)
	{
		resort_a(c, pivot, max);
		max = pivot - 1;
		pivot = find_dive_chunk(size, pivot);
		move_to_b(c, pivot, max, 0);
	}
	resort_a(c, pivot, max);
}

void	big_sol(t_ctrl *c, int size)
{
	//sol_a(c, size);
	pogo_sol(c, size);
}