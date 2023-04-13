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

void print_binary(char c)
{
	int i;

	for (i = 7; i >= 0; i--) {
		if (c & (1 << i)) {
			ft_printf("1");
		} else {
			ft_printf("0");
		}
	}
	ft_printf("\n");
}

void binary_signal(int sig, int sender_pid)
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
		ft_printf("\n#End of Message#\n");
		pid = 0;
		bit = 0;
	}
/*	if (sig == SIGUSR1)
		ft_printf("\nSIGUSR1\n");
	else if (sig == SIGUSR2)
		ft_printf("\nSIGUSR2\n");
	ft_printf("leaving bith with bit: %i\npid %i\nchar: ", bit, pid);
	print_binary(c);*/
}

static void printinfo(siginfo_t *info)
{
	static int count;

	count++;
	ft_printf("\n\tHold on:\n");
	ft_printf("Count %i:\n", count);
	
ft_printf("info->si_signo :%i\n", info->si_signo);
ft_printf("info->si_code :%i\n", info->si_code);
ft_printf("info->si_errno :%i\n", info->si_errno);
ft_printf("info->si_pid :%i\n", info->si_pid);
ft_printf("info->si_uid :%i\n", info->si_uid);
ft_printf("info->si_status :%i\n", info->si_status);
ft_printf("info->si_band :%i\n", info->si_band);
ft_printf("*info->si_addr :%p\n", info->si_addr);
//ft_printf("info->sigval_int :%i\n", info->sigval.si_value->sival_int);
//ft_printf("*info->sigval_ptr :%i\n", *info->sigval.si_value->sival_ptr);
/*
info->si_signo;
info->si_code;
info->si_errno;
info->si_pid;
info->si_uid;
info->si_status;
info->si_band;
*info->si_addr;
info->sigval->si_value->sival_int;
*info->sigval->si_value->sival_ptr
*/

}

static void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static int count;

	printinfo(info);
	if (sig == SIGUSR1 || sig == SIGUSR2)
		binary_signal(sig, info->si_pid);
	if (sig == SIGINT)
	{
		if (!count)
/*			ft_printf("\nAh, so you wanna quit the server?\n");
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
	return (0);
}
