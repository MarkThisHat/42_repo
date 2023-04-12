/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:22:12 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/12 19:30:49 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minitalk.h"

volatile sig_atomic_t	g_andalf = 0;


static void over_kill(int pid)
{
	g_andalf = 1;
	if (g_andalf)
	{
		kill(pid, SIGUSR2);
		g_andalf = 0;
	}
	if (!g_andalf)
		kill(pid, SIGUSR1);
}

static void binary_signal(int sig, int sender_pid)
{
	static t_msg	talk;
	
	if (talk.pid && talk.pid != sender_pid)
		return ;
	if (!talk.c && !talk.pid && !talk.bit)
	{
		talk.pid = sender_pid;
		talk.bit = 7;
		over_kill(talk.pid);
		return ;
	}
	if (sig == SIGUSR1)
		talk.c |= (1 << talk.bit);
	else if (sig == SIGUSR2)
		talk.c &= ~(1 << talk.bit);
	talk.bit--;
	if (talk.bit < 0)
	{
		if (talk.c)
		{
			write(1, &talk.c, 1);
			talk.bit = 7;
			talk.c = 0;
		}
		else
		{
			talk = (t_msg){0};
			over_kill(sender_pid);
			return ;
		}
	}
	over_kill(talk.pid);
//	print_binary(talk.c);
}

static void	sig_handler(int sig, siginfo_t *info, void *context)
{
//	static int count;
//	g_andalf = sig;
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		//kill(info->si_pid, SIGUSR1);
		binary_signal(sig, info->si_pid);
	}
	if (sig == SIGINT)
/*	{
		if (!count)
			ft_printf("\nAh, so you wanna quit the server?\n");
		else if (count == 1)
			ft_printf("\nGonna have to try harder than that\n");
		else if (count == 2)
			ft_printf("\nKeep trying, chump\n");
		else if (count == 3)
			ft_printf("\nGetting closer, are we?\n");
		else if (count == 4)
			ft_printf("\nOnce more, with feeling\n");
		else if (count == 5)*/
		{
			ft_printf("\nOk, goodbye and thanks for all the signals!\n");
			exit (0);
		}
//		count++;
//	}
	(void)context;
//	(void)info;
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
		;
	return (0);
}
