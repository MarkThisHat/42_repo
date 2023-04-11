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
	static unsigned char	c;
	static int	pid;
	static int	bit;

	if (pid && pid != sender_pid)
		return ;
	if (!c && !pid && !bit)
	{
		pid = sender_pid;
		bit = 7;
	}
	if (sig == SIGUSR1)
		c |= (1 << bit);
	bit--;
	if (bit < 0 && c)
	{
		ft_printf("%c", c);
		bit = 7;
		c = 0;
	}
	else if (bit < 0 && !c)
	{
		pid = 0;
		bit = 0;
	}
}

static void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static int count;

	if (sig == SIGUSR1 || sig == SIGUSR2)
		binary_signal(sig, info->si_pid);
	if (sig == SIGINT)
	{
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
		count++;
	}
	(void)context;
	(void)info;
}

int	main(void)
{
	struct sigaction s_action;

	s_action.sa_handler = NULL;
	s_action.sa_mask = (sigset_t){0};
	s_action.sa_flags = SA_SIGINFO;
	s_action.sa_sigaction = &sig_handler;
	sigaction(SIGUSR1, &s_action, NULL);
	sigaction(SIGUSR2, &s_action, NULL);
	sigaction(SIGINT, &s_action, NULL);
	ft_printf("Server ID is %i\n", getpid());
	while (42)
		sleep(1);
	return (0);
}
