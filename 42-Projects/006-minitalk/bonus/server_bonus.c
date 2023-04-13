/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:22:12 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/12 20:01:24 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minitalk.h"

volatile sig_atomic_t	g_andalf = 0;

static void	process_character(unsigned char *c, int *pid, int *bit)
{
	if (*c)
	{
		write(1, c, 1);
		*bit = 7;
		*c = 0;
	}
	else
	{
		ft_printf("\n\n#End of Message from PID %i#\n", *pid);
		ft_printf("\n#Initiating advanced confirmation protocol#\n\n");
		ft_printf("\t\"Marco?\"\n");
		kill(*pid, SIGUSR2);
		*pid = 0;
		*bit = 0;
	}
}

static void binary_signal(int sig, int sender_pid)
{
	static unsigned char	c;
	static int	pid;
	static int	bit;

	if (pid && pid != sender_pid)
		return ;
	if (!c && !pid && !bit)
	{
		pid = sender_pid;
		ft_printf("\n#Start of message from PID %i#\n\n", pid);
		bit = 7;
	}
	if (sig == SIGUSR1)
		c |= (1 << bit);
	bit--;
	if (bit < 0)
		process_character(&c, &pid, &bit);
	g_andalf = 1;
	kill(sender_pid, SIGUSR1);
}

static void sig_handler(int sig, siginfo_t *info, void *context)
{
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		g_andalf = 0;
		binary_signal(sig, info->si_pid);
	}
	if (sig == SIGINT)
		exit(0);
	(void)context;
}

int	main(void)
{
	struct sigaction s_action;
	sigset_t	ice;

	sigemptyset(&ice);
	s_action.sa_handler = NULL;
	s_action.sa_mask = ice;
	s_action.sa_flags = SA_SIGINFO;
	s_action.sa_sigaction = &sig_handler;
	sigaction(SIGUSR1, &s_action, NULL);
	sigaction(SIGUSR2, &s_action, NULL);
	sigaction(SIGINT, &s_action, NULL);
	ft_printf("Server ID is %i\n", getpid());
	while (42)
		sleep(1);
}
