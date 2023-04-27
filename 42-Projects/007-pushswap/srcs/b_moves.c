/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:49:27 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/26 22:20:36 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_b(t_ctrl *c)
{
	if (c->size_b < 2)
		return (0);
	switch_adj_nodes(c->head_b, c->head_b->next);
	c->head_b = c->head_b->prev;
	if (c->size_b == 2)
		c->tail_b = c->head_b->next;
	return(SB);
}

int	rotate_b(t_ctrl *c)
{
	t_item	*temp;

	if (c->size_b < 2)
		return (0);
	if (c->size_b == 2)
		return (swap_b(c) - SB + RB);
	temp = c->head_a;
	c->head_a = c->head_a->next;
	temp = sever_node(temp);
	c->tail_a = place_node(temp, c->tail_a);
	return(RB);
}

int	rev_rotate_b(t_ctrl *c)
{
	t_item	*temp;

	if (c->size_b < 2)
		return (0);
	if (c->size_b == 2)
		return (swap_b(c) - SB + RRB);
	temp = c->tail_b;
	c->tail_b = c->tail_b->prev;
	temp = sever_node(temp);
	c->head_b = place_node(temp, c->head_b);
	return(RRB);
}

int		push_a(t_ctrl *c)
{
	t_item	*temp;

	if (!c->size_b)
		return (0);
	temp = c->head_b;
	c->head_b = c->head_b->next;
	temp = sever_node(temp);
	if (!c->size_a)
		c->tail_a = temp;
	if (c->size_a == 1)
	{
		c->head_a->prev = temp;
		temp->next = c->head_a;
	}
	if (c->size_a < 2)
		c->head_a = temp;
	if (c->size_a++ > 1)
		c->head_a = place_node(temp, c->head_a);
	if (!--c->size_b)
	{
		c->head_b = NULL;
		c->tail_b = NULL;
	}
	return(PA);
}