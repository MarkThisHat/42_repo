/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:23:57 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/12 20:18:31 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minitalk.h"

sig_atomic_t	trade_signals(sig_atomic_t oldsig, int newsig)
{
	int	err;
	
	err = kill()	
}

void	leave_program(char *str, int return_code)
{
		if (return_code == 0)
				exit (0);
		ft_putstr_fd(str, 2);
		exit (return_code);
}

/*
	recebi SIGUSR1 (old signal)
	envio SIGUSR2
	pauso até receber SIGUSR1
	vida que segue



client:

0110: 
manda SIGUSR2



*/