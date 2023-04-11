/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:54:24 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/11 17:36:13 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minitalk.h"

static void send_bit(int bit, int pid)
{
	if (!bit)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
}

static void send_char(unsigned char c, int pid)
{
	int	i;

	i = 7;
	while (i + 1)
	{
		send_bit((c >> i) & 1, pid);
		i--;
        usleep(4200);
	}
	ft_printf(" %c", c);
	ft_printf(" \n");
}

static void	send_message(char *str, int pid)
{
	while (*str)
	{
		send_char(*str, pid);
		str++;
	}
	send_char(0, pid);
}

int	main(int argc, char **argv)
{
	int	pid;
	struct sigaction s_action;

	s_action.sa_handler = NULL;
	s_action.sa_mask = (sigset_t){0};
	s_action.sa_flags = SA_SIGINFO;
	s_action.sa_sigaction = &sig_handler;
	sigaction(SIGUSR1, &s_action, NULL);
	sigaction(SIGUSR2, &s_action, NULL);

	if (argc != 3)
		leave_program("Usage ./client [server PID] [message]\n", 1);
	pid = ft_atoi(argv[1]);
	if (pid < 1)
		leave_program("Server PID has to be numeric and positive\n", 1);
	send_message(argv[2], pid);
}
