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
	usleep(100);
//	ft_printf("%i\n", pid);
}

static void send_char(unsigned char c, int pid)
{
	static int	i;
	static char	sending;

	if (!sending && c)
	{
		i = 7;
		sending = c;
	}
	if (c)
		send_bit((sending >> i) & 1, pid);
	else
		send_bit((c >> i) & 1, pid);
	i--;
	ft_printf("sendchar %i\n", i);
	if (i < 0)
		sending = 0;
}

static void	send_message(char *str, int pid)
{
	static char	*message;
	static int	i;

	if (str)
		message = str;
	if (*message)
	{
		send_char(*message, pid);
		ft_printf("i is %i and msg is %c\n", i, *message);
		if (i < 7)
			i++;
		else
		{
			i = 0;
			message++;
		}
	}
	else
		send_char(0, pid);
}

static void	sig_c_handler(int sig, siginfo_t *info, void *context)
{
	if (sig == SIGUSR1)
		send_message(0, info->si_pid);
	if (sig == SIGUSR2)
		leave_program("Success", 0);
	(void)context;
}

int	main(int argc, char **argv)
{
	int	pid;
	struct sigaction s_action;

	if (argc != 3)
		leave_program("Usage ./client [server PID] [message]\n", 1);
	pid = ft_atoi(argv[1]);
	if (pid < 1)
		leave_program("Server PID has to be numeric and positive\n", 1);
	s_action.sa_handler = NULL;
	s_action.sa_mask = (sigset_t){0};
	s_action.sa_flags = SA_SIGINFO;
	s_action.sa_sigaction = &sig_c_handler;
	sigaction(SIGUSR1, &s_action, NULL);
	sigaction(SIGUSR2, &s_action, NULL);
	send_message(argv[2], pid);
	sleep(10);
}
