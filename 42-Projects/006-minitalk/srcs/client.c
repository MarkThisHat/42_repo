/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:54:24 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/12 19:33:13 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minitalk.h"

volatile sig_atomic_t	g_andalf = 0;

static void send_bit(int bit, int pid)
{
	int err;

	if (!bit)
	{
		err = kill(pid, SIGUSR2);
		ft_printf("0");
	}
	else
	{	
		err = kill(pid, SIGUSR1);
		ft_printf("1");
	}
	if (err)
		leave_program("Failed to send signal\n", 1);
	while (!g_andalf)
		pause();
	g_andalf = 0;
}

static void	send_message(char *str, int pid)
{
	static char	*message;
	static int	i;
	static int	last;

	if (str)
	{
		message = str;
		i = 7;
	}
	send_bit((*message >> i) & 1, pid);
	i--;
	if (i < 0 && *message)
	{
		i = 7;
		message++;
	}
	if (!*message)
		last++;
	if (last > 8)
		leave_program("\nkthxbye\n", 42);
}

static void	sig_c_handler(int sig, siginfo_t *info, void *context)
{
	if (sig == SIGUSR1)
		send_message(0, info->si_pid);
	else if (sig == SIGUSR2)
		g_andalf = 42;
	(void)context;
}

int	main(int argc, char **argv)
{
	int	pid;
	sigset_t	ice;
	struct sigaction s_action;

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
	sigaction(SIGUSR2, &s_action, NULL);
	send_message(argv[2], pid);
	while (42)
		;
}
