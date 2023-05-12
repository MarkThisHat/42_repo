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

void	move_stack(int next_move, t_item *curr, t_item *op, int *actions)
{
	int	moves[4];
	int	cost;

	while (curr->i != next_move)
		curr = curr->next;
	cost = cal_cost(curr, op, moves);
	if (cost == moves[0])
	{
		actions[0] = RA;
		actions[1] = RB;
	}
	else if (cost == moves[1])
	{
		actions[0] = RRA;
		actions[1] = RRB;
	}
	else if (cost == moves[2])
	{
		actions[0] = RRA;
		actions[1] = RB;
	}
	else if (cost == moves[3])
	{
		actions[0] = RA;
		actions[1] = RRB;
	}
}

void	motion_a_to_b(t_ctrl *c, int next_move)
{
	int	actions[2];
	int	b_item;
	
	move_stack(next_move, c->head_a, c->head_b, actions);
	while (c->head_a->i != next_move)
		c->stream = log_move(do_move(c, actions[0]), c->stream, c);
	b_item = (find_cushy_spot(c->head_a->i, c->head_b));
	while (c->head_b->i != b_item)
		c->stream = log_move(do_move(c, actions[1]), c->stream, c);
	c->stream = log_move(push_b(c), c->stream, c);
}

void	greedy_swap(t_ctrl *c)
{
	t_item	*temp;
	int		next_move;
	int		current;
	int		quickest;

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
		temp = temp->next;
	}
	motion_a_to_b(c, next_move);
}

void	sol_c(t_ctrl *c, int size)
{
	int	target;

	c->answer = first_move_big(c, PB);
	c->stream = get_stream(c->answer);
	c->stream = log_move(push_b(c), c->stream, c);
	c->stream = log_move(push_b(c), c->stream, c);
	sort_three(c, c->head_b, 1);
	while (c->size_a > 3)
		greedy_swap(c);
	sort_three(c, c->head_a, 0);
	greedy_swap(c);
	greedy_swap(c);
	target = find_cushy_spot(c->head_a->i, c->head_b);
	if (climb_target(c->tail_b, target) > dive_target(c->head_b, target))
		while (c->head_b->i != target)
			c->stream = log_move(rotate_b(c), c->stream, c);
	else
		while (c->head_b->i != target)
			c->stream = log_move(rev_rotate_b(c), c->stream, c);
	while (c->size_b)
			c->stream = log_move(push_a(c), c->stream, c);
	if (climb_target(c->tail_a, 0) > dive_target(c->head_a, 0))
		while (c->head_a->i)
			c->stream = log_move(rotate_a(c), c->stream, c);
	else
		while (c->head_a->i)
			c->stream = log_move(rev_rotate_a(c), c->stream, c);
	(void)size;
}
