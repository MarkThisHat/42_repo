/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:49:27 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/25 16:46:33 by maalexan         ###   ########.fr       */
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
	temp = c->head_a;
	move_edge_nodes(c->head_a, c->tail_a);
	c->head_a = c->tail_a;
	c->tail_a = temp;
	return(RA);
}

void	move_edge_nodes(t_item *moved, t_item *edged)
{
	t_item	*edged_prev;
	t_item	*edged_next;
	t_item	*moved_prev;
	t_item	*moved_next;

	if (moved_prev)
		moved->prev->next = edged;
	if (edged_next)
}
