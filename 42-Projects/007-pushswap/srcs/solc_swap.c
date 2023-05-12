/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solc_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:17:38 by maalexan          #+#    #+#             */
/*   Updated: 2023/05/12 11:12:01 by maalexan         ###   ########.fr       */
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
	int	closer;

	bigger = find_small_or_big(oppo_head, 1);
	smaller = find_small_or_big(oppo_head, 0);
	if (item > bigger)
		return (bigger);
	if (item < smaller)
		return (item);
	while (oppo_head->next)
	{
		if (oppo_head->i < item)
			closer = oppo_head->i;
		oppo_head = oppo_head->next;
	}
	while (oppo_head)
	{
		if (oppo_head->i > closer && oppo_head->i < item)
			closer = oppo_head->i;
		oppo_head = oppo_head->prev;
	}
	return (closer);
}

int find_cushy_spot(int item, t_item *oppo_head)
{
	int closer = -1;
	int second_biggest = -1;

	while (oppo_head)
	{
		if (oppo_head->i < item && (closer == -1 || item - oppo_head->i < item - closer))
		{
			closer = oppo_head->i;
		}

		// Update the second biggest value
		if (oppo_head->i > second_biggest && (closer == -1 || oppo_head->i != closer))
		{
			second_biggest = oppo_head->i;
		}

		oppo_head = oppo_head->next;
	}

	// If the item is greater than all the values in the list,
	// return the second biggest value.
	if (closer == -1)
	{
		return second_biggest;
	}

	return closer;
}


*/

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
/*
int	find_cushy_spot(int item, t_item *oppo_head)
{
	int	bigger;
	int	smaller;
	int	closer;

	bigger = oppo_head->i;
	smaller = oppo_head->i;
	while (oppo_head->next)
	{
		if (oppo_head->i < item)
			closer = oppo_head->i;
		if (oppo_head->i > bigger)
			bigger = oppo_head->i;
		if (oppo_head->i < smaller)
			smaller = oppo_head->i;
		oppo_head = oppo_head->next;
	}
	while (oppo_head)
	{
		if (oppo_head->i > closer && oppo_head->i < item)
			closer = oppo_head->i;
		oppo_head = oppo_head->prev;
	}
	if (item > bigger)
		return (bigger);
	if (item < smaller)
		return (item);
	return (closer);

	 ./push_swap 13 9 15 8 17 7 6 10 5 4 14 3 2 1 0 16 11 12
}*/

/*
int	cheapest_two(int ra, int rra, int rb, int rrb)
{
	ra + rb
	rra + rrb
	ra + rrb
	rra + rb
}*/

int	compute_cost(int ra, int rra, int rb, int rrb)
{
	int	i;
	int	cheap;
	int	cost[4];

	if (ra > rb)
		cost[0] = ra;
	else
		cost[0] = rb;
	if (rra > rrb)
		cost[1] = rra;
	else
		cost[1] = rrb;
	cost[2] = rra + rb;
	cost[3] = ra + rrb;
	i = 0;
	cheap = cost[0];
	while (i++ < 3)
		if (cost[i] < cheap)
			cheap = cost[i];
	return (cheap);
}

int find_cushy_spot(int item, t_item *op)
{
	int closer;
	int biggest;

	closer = -1;
	biggest = -1;
	while (op)
	{
		if (op->i < item && (closer == -1 || item - op->i < item - closer))
			closer = op->i;
		if (op->i > biggest && (closer == -1 || op->i != closer))
			biggest = op->i;
		op = op->next;
	}
	if (closer == -1)
		return (biggest);
	return (closer);
}

int	*put_cost(int *moves)
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;

	ra = moves[0];
	rra = moves[1];
	rb = moves[2];
	rrb = moves[3];
	if (ra > rb)
		moves[0] = ra;
	else
		moves[0] = rb;
	if (rra > rrb)
		moves[1] = rra;
	else
		moves[1] = rrb;
	moves[2] = rra + rb;
	moves[3] = ra + rrb;
	return (moves);
}

int		cal_cost(t_item *package, t_item *oppo_head, int *moves)
{
	int	rot;
	int	rev;
	int	target;
	int	climb;
	int	dive;

	rot = count_tails_or_head(package, 1);
	rev = count_tails_or_head(package, 0) + 1;
	target = (find_cushy_spot(package->i, oppo_head));
	dive = dive_target(oppo_head, target);
	while (oppo_head->next)
		oppo_head = oppo_head->next;
	climb = climb_target(oppo_head, target);
	if (!moves)
	{
	ft_printf("Item: %i index %i\n", package->n, package->i);
	ft_printf("Rotate A: %i\nReverse Rotate A: %i\n", rot, rev);
	ft_printf("Should be right above %i\n", target);
	ft_printf("Rotate B: %i\nReverse Rotate B: %i\n", dive - 1, climb);
	ft_printf("I should be comparing rotates %i and %i and reverses %i and %i\n", rot, dive -1, rev, climb);
	ft_printf("This move's cost: %i\n", compute_cost(rot, rev, dive - 1, climb));
	}
	if (moves)
	{
		moves[0] = rot;
		moves[1] = rev;
		moves[2] = dive - 1;
		moves[3] = climb;
		moves = put_cost(moves);
	}
	return (compute_cost(rot, rev, dive - 1, climb));
}

void	get_move_motion(t_ctrl *c, int next_move)
{
	int	movements[2];
	
	movements = make_move(next_move, c->head_a, c->head_b);
}

void	make_move(int next_move, t_item *curr, t_item *op)
{
	int	moves[4];
	int	cost;

	while (curr->i != next_move)
		curr = curr->next;
	cost = cal_cost(curr, op, moves);
	if (cost == moves[0])
		ft_printf("RA and RB\n");
	if (cost == moves[1])
		ft_printf("RRA and RRB\n");
	if (cost == moves[2])
		ft_printf("RRA and RB\n");
	if (cost == moves[3])
		ft_printf("RA and RRB\n");
}

void	sol_c(t_ctrl *c, int size)
{
	t_item	*temp;
	int		next_move;
	int		current;
	int		quickest;

	c->answer = first_move_big(c, PB);
	c->stream = get_stream(c->answer);
	c->stream = log_move(push_b(c), c->stream, c);
	c->stream = log_move(push_b(c), c->stream, c);
	sort_three(c, c->head_b, 1);
	quickest = cal_cost(c->head_a, c->head_b, NULL);
	temp = c->head_a->next;
	next_move = c->head_a->i;
	while (temp)
	{
		current = cal_cost(temp, c->head_b, NULL);
		if (current < quickest)
		{
			quickest = current;
			next_move = temp->i;
		}
		make_move(temp->i, c->head_a, c->head_b);
		write(1, "\n\n", 2);
		temp = temp->next;
	}
	ft_printf("\nThe quickest move should be index: %i\n\n", next_move);
	make_move(next_move, c->head_a, c->head_b);
	print_full_stacks(c);
	(void)size;
}
