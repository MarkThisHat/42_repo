/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:06:23 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/10 22:07:03 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minitalk.h"

static t_msg *set_node(t_msg *node, int sender_pid)
{
	if (!node->pid)
		node->pid = sender_pid;
	if (node->pid && node->pid != sender_pid)
	{
		if (!node->next)
		{
			node->next = malloc(sizeof(t_msg));
			if (!node->next)
				leave_program("No memory available\n", 1);
			*node->next = (t_msg){0};
		}
		return (set_node(node->next, sender_pid));
	}
	if (!node->msg)
	{
		if (!node->len)
			node->msg = &node->msg_size[0];
		else
			node->msg = ft_calloc(node->len + 1, sizeof(char));
		if (!node->msg)
			leave_program("No memory available\n", 1);
		node->bit = 7;
	}
	return (node);
}

static t_msg	*received_null_byte(t_msg *node)
{
	t_msg *temp;

	temp = node->next;
	if (!node->len)
	{
		node->len = ft_atoi(node->msg_size);
		node->msg = NULL;
		node->bit = 0;
	}
	else
	{
		node->msg -= node->len;
		ft_printf("%s\n", node->msg);
		free(node->msg);
		*node = (t_msg){0};
	}
	return (temp);
}

static void treat_byte(t_msg *node, int sig)
{
	if (sig == SIGUSR1)
		node->c |= (1 << node->bit);
	node->bit--;
	if (node->bit < 0 && node->c)
	{
		*node->msg = node->c;
		node->msg++;
		node->c = 0;
		node->bit = 7;
	}
	else if (node->bit < 0 && !node->c)
		node->next = received_null_byte(node);
}

void binary_signal(int sig, int sender_pid)
{
	static t_msg	node;
	t_msg			*ptr;

    if (sig == SIGINT)
		clear_list(&node);
	ptr = set_node(&node, sender_pid);
	treat_byte(ptr, sig);
}
