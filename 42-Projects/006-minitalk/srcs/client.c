/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:54:24 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/13 16:55:39 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minitalk.h"

volatile sig_atomic_t	g_andalf = 0;

static void	send_bit(int bit, int pid)
{
	g_andalf = 0;
	while (!g_andalf)
	{
		if (!bit)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(42000);
	}
}

static void	send_char(unsigned char c, int pid)
{
	int	i;

	i = 7;
	while (i + 1)
	{
		send_bit((c >> i) & 1, pid);
		i--;
	}
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

static void	sig_c_handler(int sig, siginfo_t *info, void *context)
{
	if (sig == SIGUSR1)
		g_andalf = 1;
	(void)info;
	(void)context;
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	s_action;
	sigset_t			ice;

	if (argc != 3)
		leave_program("Usage ./client [server PID] [message]\n", 1);
	pid = ft_atoi(argv[1]);
	if (pid < 1)
		leave_program("Server PID has to be numeric and positive\n", 1);
	sigemptyset(&ice);
	s_action.sa_handler = NULL;
	s_action.sa_mask = ice;
	s_action.sa_flags = SA_SIGINFO;
	s_action.sa_sigaction = &sig_c_handler;
	sigaction(SIGUSR1, &s_action, NULL);
	send_message(argv[2], pid);
}
