/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solc_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:17:38 by maalexan          #+#    #+#             */
/*   Updated: 2023/05/15 12:02:37 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_actions(int *act, int a, int b)
{
	act[0] = a;
	act[1] = b;
}

static void	move_stack(int next_move, t_item *curr, t_item *op, int *actions)
{
	int	moves[4];
	int	cost;

	while (curr->i != next_move)
		curr = curr->next;
	cost = cal_cost(curr, op, moves);
	if (cost == moves[0])
		fill_actions(actions, RA, RB);
	else if (cost == moves[1])
		fill_actions(actions, RRA, RRB);
	else if (cost == moves[2])
		fill_actions(actions, RRA, RB);
	else if (cost == moves[3])
		fill_actions(actions, RA, RRB);
}

static void	motion_a_to_b(t_ctrl *c, int next_move)
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

static void	greedy_swap(t_ctrl *c)
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

void	cheap_sol(t_ctrl *c)
{
	c->answer = first_move_big(c, PB);
	c->stream = get_stream(c->answer);
	c->stream = log_move(push_b(c), c->stream, c);
	c->stream = log_move(push_b(c), c->stream, c);
	sort_three(c, c->head_b, 1);
	while (c->size_a > 1)
		greedy_swap(c);
	motion_a_to_b(c, c->head_a->i);
	while (c->size_b)
		c->stream = log_move(push_a(c), c->stream, c);
	if (climb_target(c->tail_a, 0) > dive_target(c->head_a, 0))
		while (c->head_a->i)
			c->stream = log_move(rotate_a(c), c->stream, c);
	else
		while (c->head_a->i)
			c->stream = log_move(rev_rotate_a(c), c->stream, c);
}
