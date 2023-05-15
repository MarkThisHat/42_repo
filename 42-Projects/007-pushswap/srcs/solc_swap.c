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

void	cheap_sol(t_ctrl *c, int size)
{
	c->answer = first_move_big(c, PB);
	c->stream = get_stream(c->answer);
	c->stream = log_move(push_b(c), c->stream, c);
	c->stream = log_move(push_b(c), c->stream, c);
	sort_three(c, c->head_b, 1);
	while (c->size_a > 1)
		greedy_swap(c);
	while (c->size_b)
	{
		c->stream = log_move(push_a(c), c->stream, c);
		if (c->tail_a->i == c->head_a->i - 1)
			c->stream = log_move(rev_rotate_a(c), c->stream, c);
		if (c->head_a->i == size - 1)
			c->stream = log_move(rotate_a(c), c->stream, c);
	}
	if (climb_target(c->tail_a, 0) > dive_target(c->head_a, 0))
		while (c->head_a->i)
			c->stream = log_move(rotate_a(c), c->stream, c);
	else
		while (c->head_a->i)
			c->stream = log_move(rev_rotate_a(c), c->stream, c);
	if (is_sorted(c))
		return ;
}

/*

29 26 -32 -4 -37 -46 -28 -22 -39 -14 -24 41 -29 -19 10 47 -41 43 30 2 42 -13 -38 25 -44 11 6 44 -12 -17 3 -33 -27 14 9 -31 -5 -8 -40 36 -30 13 -16 -43 -18 0 -21 -9 16 -2 -25 -1 35 -23 -26 7 -15 27 -11 23 -36 8 40 34 -7 39 50 31 45 18 -45 32 20 22 4 33 1 -10 24 46 38 48 5 -3 17 -6 -35 -42 15 -20 -34 28 19 -47 -49 -48 37 49 12 21 

-29 36 49 -11 39 33 -28 -30 20 41 -41 -42 -21 -20 -27 29 -26 -7 -14 43 -5 -32 27 31 40 -33 -34 -10 -39 5 44 37 2 -25 -4 21 48 12 23 -22 -35 -24 30 42 -48 0 38 10 13 -8 32 9 45 -49 -15 7 22 -47 -46 -44 26 11 14 -12 17 -3 24 50 -23 18 -38 -45 46 1 -37 -1 34 -2 4 -36 8 -6 6 -31 47 15 28 35 25 -40 -17 16 3 -43 -18 -16 19 -13 -9 -19 

-3 -1 18 -49 30 -35 -12 -47 -34 40 43 -22 33 1 -38 -16 -37 39 27 24 49 45 -23 0 -42 11 35 17 22 12 -14 29 -11 -30 50 26 20 8 -17 -33 -2 9 -48 -29 23 -15 -27 42 -44 -18 21 -36 4 34 -21 15 -46 25 28 -6 -40 -41 -24 -10 -19 38 6 47 7 48 -20 14 -32 -39 44 -5 36 -26 10 13 16 32 -45 19 -9 -25 -43 2 46 37 -13 5 3 -28 -8 41 -4 31 -7 -31 

*/