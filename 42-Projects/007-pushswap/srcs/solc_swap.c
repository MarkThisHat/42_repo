/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solc_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:17:38 by maalexan          #+#    #+#             */
/*   Updated: 2023/05/10 20:01:36 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
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
}*/

//pog

int		count_tails_or_head(t_item *item, int tails)
{
	int	i;

	i = 0;
	while (item)
	{
		if (tails)
			item = item->prev;
		else
			item = item->next;
		if (item)
			i++;
	}
	return (i);
}

int	find_small_or_big(t_item *item, int big)
{
	int	n;
	int	sign;

	n = item->i;
	sign = 1;
	if (big)
		sign = -1;
	while (item)
	{
		if (item->i * sign < n * sign)
			n = item->i;
		item = item->next;
	}
	return (n);
}

int	find_cushy_spot(int item, t_item *oppo_head)
{
	int	bigger;
	int	smaller;

	bigger = find_small_or_big(oppo_head, 1);
	smaller = find_small_or_big(oppo_head, 0);
	if (item > bigger)
		return (bigger);
	if (item < smaller)
		return (smaller);
	while (item < oppo_head->i)
		oppo_head = oppo_head->next;
	return (oppo_head->i);
}

int		cal_cost(t_item *package, t_item *oppo_head)
{
	int	rot;
	int	rev;
	int	target;
	int	climb = 3;
	int	dive;

	rot = count_tails_or_head(package, 1);
	rev = count_tails_or_head(package, 0);
	ft_printf("Item: %i index %i\n", package->n, package->i);
	ft_printf("To head: %i\nTo tails: %i\n", rot, rev);
	target = (find_cushy_spot(package->i, oppo_head));
	ft_printf("Should be above %i\n", target);
	dive = dive_target(oppo_head, target);
	while (oppo_head->next)
		oppo_head = oppo_head->next;
	climb = climb_target(oppo_head, target);
	ft_printf("Rotatin: %i, Reverse: %i\n\n", dive - 1, climb);
	return (oppo_head->i);
}

void	sol_c(t_ctrl *c, int size)
{
	t_item	*temp;

	c->answer = first_move_big(c, PB);
	c->stream = get_stream(c->answer);
	c->stream = log_move(push_b(c), c->stream, c);
	c->stream = log_move(push_b(c), c->stream, c);
	c->stream = log_move(push_b(c), c->stream, c);
	sort_three(c, c->head_b, 1);
	temp = c->head_a;
	while (temp)
	{
		cal_cost(temp, c->head_b);
		temp = temp->next;
	}
	print_full_stacks(c);
	c->stream = log_move(rotate_a(c), c->stream, c);
	print_full_stacks(c);
	(void)size;
}
