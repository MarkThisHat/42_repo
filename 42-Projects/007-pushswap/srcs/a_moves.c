/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:49:27 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/26 22:18:51 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(t_ctrl *c)
{
	if (c->size_a < 2)
		return (0);
	switch_adj_nodes(c->head_a, c->head_a->next);
	c->head_a = c->head_a->prev;
	if (c->size_a == 2)
		c->tail_a = c->head_a->next;
	return(SA);
}

int	rotate_a(t_ctrl *c)
{
	t_item	*temp;

	if (c->size_a < 2)
		return (0);
	if (c->size_a == 2)
		return (swap_a(c) - SA + RA);
	temp = c->head_a;
	c->head_a = c->head_a->next;
	temp = sever_node(temp);
	c->tail_a = place_node(temp, c->tail_a);
	return(RA);
}

int	rev_rotate_a(t_ctrl *c)
{
	t_item	*temp;

	if (c->size_a < 2)
		return (0);
	if (c->size_a == 2)
		return (swap_a(c) - SA + RRA);
	temp = c->tail_a;
	c->tail_a = c->tail_a->prev;
	temp = sever_node(temp);
	c->head_a = place_node(temp, c->head_a);
	return(RRA);
}

int		push_b(t_ctrl *c)
{
	t_item	*temp;

	if (!c->size_a)
		return (0);
	temp = c->head_a;
	c->head_a = c->head_a->next;
	temp = sever_node(temp);
	if (!c->size_b)
		c->tail_b = temp;
	if (c->size_b == 1)
	{
		c->head_b->prev = temp;
		temp->next = c->head_b;
	}
	if (c->size_b < 2)
		c->head_b = temp;
	if (c->size_b++ > 1)
		c->head_b = place_node(temp, c->head_b);
	if (!--c->size_a)
	{
		c->head_a = NULL;
		c->tail_a = NULL;
	}
	return(PB);
}
