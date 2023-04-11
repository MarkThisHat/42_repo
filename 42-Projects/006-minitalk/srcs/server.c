/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:22:12 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/08 22:18:20 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minitalk.h"

static void	sig_handler(int sig, siginfo_t *info, void *context)
{
	if (sig == SIGUSR1 || sig == SIGUSR2)
		binary_signal(sig, info->si_pid);
	(void)context;
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
	ft_printf("Server ID is [%i]. Press Ctrl + C to exit\n", getpid());
	while (42)
		sleep(1);
	return (0);
}
