/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:49:27 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/25 10:48:19 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(t_ctrl *c)
{
	if (c->size_a < 2)
		return (0);
	ft_printf("before %i \n", c->head_a->n);
	switch_nodes(c->head_a, c->head_a->next);
	ft_printf("after %i \n", c->head_a->n);
	c->head_a = c->head_a->prev;
	if (c->size_a == 2)
		c->tail_a = c->head_a->next;
	ft_printf("even after %i \n", c->head_a->n);
	return(SA);
}

/*
void	switch_nodes(t_item *a, t_item *b)
{
	t_item	*temp;

	if (b->next)
		b->next->prev = a;
	temp = a->next;
	a->next = b->next;
	a->prev = temp;
	b->next = b->prev;
	b->prev = a->prev;
}

	a->next = b->next;
	a->prev = a->next;
	b->next = b->prev;
	b->prev = a->prev; */


/*wtfgpt

head aponta pro item 1

item 1.prev eh NULL
item 1.next aponta pro item 2

item 2.prev aponta pro item 1
item 2.next aponta pro item 3 (ou null)


temp = item 1.next;
item 1.next = item 2.next;



int	swap_a(t_ctrl *c)
{
	t_item  *temp;
	
	if (c->size_a < 2)
		return (0);
	temp = c->head_a;
	c->head_a = c->head_a->next;
	temp->next = c->head_a->next;
	c->head_a->next = temp;
	temp->next->prev = temp;
	c->head_a->prev = NULL;
	temp->prev = c->head_a;
	return(SA);
}

*/