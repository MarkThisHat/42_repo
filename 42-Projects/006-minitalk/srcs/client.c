/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:54:24 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/07 21:18:52 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minitalk.h"

static void send_bit(int bit, int pid)
{
	if (!bit)
	{
        ft_printf("%i", bit);
		kill(pid, SIGUSR2);
	}
	else
	{
        ft_printf("%i", bit);
    	kill(pid, SIGUSR1);
	}
}

static void send_char(unsigned char c, int pid)
{
	int	i;

	i = 7;
	while (i + 1)
	{
//	    ft_printf("tick: %i\n", i);
		send_bit((c >> i) & 1, pid);
		i--;
        usleep(50);
	}
	ft_printf(" %c", c);
	ft_printf(" \n");
}

static void	send_message(char *str, int pid)
{
	while (*str)
	{
		send_char(*str, pid);
		str++;
	}
	send_char(0, pid);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		leave_program("Usage ./client [server PID] [message]\n", 1);
	pid = ft_atoi(argv[1]);
	if (pid < 1)
		leave_program("Server PID has to be numeric and positive\n", 1);
	ft_printf("Client PID %i\n", getpid());
	send_message(argv[2], pid);
}
