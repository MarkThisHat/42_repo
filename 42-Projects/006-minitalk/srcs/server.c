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

int	main(int argc, char **argv)
{
	int	pid;

	pid = getpid();
	if (argc < 2)
		ft_printf("Server ID is %i\n", pid);
	ft_printf("SIGUSR1 %i, SIGUSR2 %i\n", SIGUSR1, SIGUSR2);
	(void)argv;
}
