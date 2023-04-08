/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:22:12 by maalexan          #+#    #+#             */
/*   Updated: 2023/03/26 22:39:40 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minitalk.h"

static void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static int count;

	if (sig == SIGUSR1)
		ft_printf("SIGUSR1 received\n");
	if (sig == SIGUSR2)
		ft_printf("SIGUSR2 received\n");
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
		else if (count == 5)
		{
			ft_printf("\nK, bye\n");
			exit (0);
		}
		count++;
	}
	(void)context;
	(void)info;
//	ft_printf("info: %p, context: %p", info, context);
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
