/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 10:33:08 by maalexan          #+#    #+#             */
/*   Updated: 2023/05/13 10:33:10 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_tails_or_head(t_item *item, int tails)
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

static int	compute_cost(int ra, int rra, int rb, int rrb)
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

int	find_cushy_spot(int item, t_item *op)
{
	int	closer;
	int	biggest;

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

static int	*put_cost(int *moves)
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

int	cal_cost(t_item *package, t_item *oppo_head, int *moves)
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
