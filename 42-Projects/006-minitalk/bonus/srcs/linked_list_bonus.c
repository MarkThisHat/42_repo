/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:06:23 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/11 16:50:39 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minitalk_bonus.h"

static void	set_node(t_msg *node, int sender_pid)
{
	if (!node->pid)
		node->pid = sender_pid;
	if (node->pid && node->pid != sender_pid)
	    return ;
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
}

static void	received_null_byte(t_msg *node)
{
	if (!node->len)
	{
		node->len = ft_atoi(node->msg_size);
		node->msg = NULL;
		node->bit = 0;
	}
	else
	{
		node->msg -= node->len;
		print_utf_eight(node->msg);
		ft_printf("\n\nMarco?\n");
		free(node->msg);
		kill(node->pid, SIGUSR1);
		*node = (t_msg){0};
	}
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
		received_null_byte(node);
}

void binary_signal(int sig, int sender_pid)
{
	static t_msg	node;

	set_node(&node, sender_pid);
	treat_byte(&node, sig);
}
