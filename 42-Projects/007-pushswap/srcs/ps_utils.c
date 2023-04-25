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
