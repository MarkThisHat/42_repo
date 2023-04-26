/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:23:57 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/24 20:24:30 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leave_program(char *str, int return_code)
{
	if (return_code == 0)
		exit (0);
	ft_putstr_fd(str, 2);
	exit (return_code);
}

void	empty_stack(t_item *item)
{
	t_item	*temp;

	while (item->prev)
		item = item->prev;
	while (item)
	{
		temp = item->next;
		free(item);
		item = temp;
	}
}

void	free_and_leave(t_item *stack, int return_code)
{
	empty_stack(stack);
	exit(return_code);
}

void	set_control(t_ctrl *c, t_item *item, int size)
{
	*c = (t_ctrl){0};
	c->head_a = item;
	while (item->next)
		item = item->next;
	c->tail_a = item;
	c->size_a = size;
}

/*
void	switch_nodes(t_item *a, t_item *b)
{
	t_item	*temp_a;
	t_item	*temp_b;

	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	temp_a = a->prev;
	temp_b = b->prev;
	a->prev = a->next;
	b->prev = temp_a;
	a->next = b->next;
	b->next = temp_b;
}
*/

/*presuming this is correct
void	switch_nodes(t_item *a, t_item *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->prev = a->next;
	a->next = b->next;
	b->prev = a->prev;
	b->next = b->prev;
}
*/
/*preindy, gpt says my a->prev is going to be a problem*/




/*
void	switch_nodes(t_item *a, t_item *b)
{
	t_item	*a_prev;
	t_item	*a_next;
	t_item	*b_prev;
	t_item	*b_next;

	a_prev = a->prev;
	a_next = a->next;
	b_prev = b->prev;
	b_next = b->next;
	if (a_prev)
		a_prev->next = b->next;
	if (b_next)
		b_next->prev = b->prev;
	a->prev = b_prev;
	a->next = b_next;
	b->prev = a_prev;
	b->next = a_next;
}

*/
