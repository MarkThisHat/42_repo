/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:31:07 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/26 16:31:22 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	switch_adj_nodes(t_item *a, t_item *b)
{
	t_item	*temp;

	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	temp = b->next;
	b->next = a;
	a->next = temp;
	temp = a->prev;
	a->prev = b;
	b->prev = temp;
}

t_item	*sever_node(t_item *item)
{
	if (item->next)
		item->next->prev = NULL;
	if (item->prev)
		item->prev->next = NULL;
	item->next = NULL;
	item->prev = NULL;
	return (item);
}

t_item	*place_node(t_item *item, t_item *edge)
{
	if (edge->prev)
	{
		edge->next = item;
		item->prev = edge;
		return (item);
	}
	if (edge->next)
	{
		edge->prev = item;
		item->next = edge;
		return (item);
	}
	return (0);
}
