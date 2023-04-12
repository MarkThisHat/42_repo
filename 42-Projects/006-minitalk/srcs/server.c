/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:22:12 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/11 17:34:11 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minitalk.h"

static void binary_signal(int sig, int sender_pid)
{
	static t_msg	talk;
	if (talk.pid && talk.pid != sender_pid)
		return ;
	if (!talk.c && !talk.pid && !talk.bit)
	{
		talk.pid = sender_pid;
		talk.bit = 7;
	}
	if (sig == SIGUSR1)
		talk.c |= (1 << talk.bit);
	ft_printf("\n%i\n", (1 << talk.bit));
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
			talk = (t_msg){0};
	}
	kill(sender_pid, SIGUSR1);
	print_binary(talk.c);
}

static void	sig_handler(int sig, siginfo_t *info, void *context)
{
//	static int count;

	if (sig == SIGUSR1 || sig == SIGUSR2)
		binary_signal(sig, info->si_pid);
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
