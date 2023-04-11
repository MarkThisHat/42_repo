/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:22:12 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/11 16:48:44 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minitalk_bonus.h"

static void	sig_handler(int sig, siginfo_t *info, void *context)
{
	if (sig == SIGUSR1 || sig == SIGUSR2)
		binary_signal(sig, info->si_pid);
	(void)context;
}

int	main(void)
{
	struct sigaction s_action;

	set_sigaction(&s_action);
	s_action.sa_sigaction = &sig_handler;
	sigaction(SIGUSR1, &s_action, NULL);
	sigaction(SIGUSR2, &s_action, NULL);
	ft_printf("Server ID is [%i]\n", getpid());
	while (42)
		sleep(1);
	return (0);
}