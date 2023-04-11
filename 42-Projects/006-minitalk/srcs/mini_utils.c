/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:23:57 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/07 11:24:24 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minitalk.h"

void	leave_program(char *str, int return_code)
{
		if (return_code == 0)
				exit (0);
		ft_putstr_fd(str, 2);
		exit (return_code);
}

void	clear_list(t_msg *node)
{
	t_msg *tmp;

	ft_printf("pog\n");
	while(node->next)
	{
		tmp = node->next;
		free(node->next);
		node->next = tmp;
	}
	leave_program("clear_list ok", 0);
}

void print_binary(char c)
{
	int i;

	for (i = 7; i >= 0; i--) {
		if (c & (1 << i)) {
			ft_printf("1");
		} else {
			ft_printf("0");
		}
	}
	ft_printf("\n");
}
