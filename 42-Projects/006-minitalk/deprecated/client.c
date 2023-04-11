/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:54:24 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/08 23:16:11 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minitalk.h"

static void send_bit(int bit, int pid)
{
	if (!bit)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
}

static void send_char(unsigned char c, int pid)
{
	int	i;

	i = 7;
	while (i + 1)
	{
		send_bit((c >> i) & 1, pid);
		i--;
		usleep(1000);
	}
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
	char	*len;
	int		pid;
	int		length;

	if (argc != 3)
		leave_program("Usage ./client [server PID] [message]\n", 1);
	pid = ft_atoi(argv[1]);
	if (pid < 1)
		leave_program("Server PID has to be numeric and positive\n", 1);
	length = ft_strlen(argv[2]);
	if (length > 99999)
		leave_program("Cannot send message with 100k characters or more\n", 1);
	len = ft_itoa(length);
	send_message(len, pid);
	free(len);
	len = NULL;
	send_message(argv[2], pid);
}
