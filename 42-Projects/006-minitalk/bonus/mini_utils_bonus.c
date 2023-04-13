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

void	leave_program(char *str, int return_code)
{
		if (return_code == 0)
				exit (0);
		ft_putstr_fd(str, 2);
		exit (return_code);
}

/*
Testing emojis:
echo -e '\xDF\xB7''\xF0\x9F\x98\x80''\xC3\xB8''\xE1\x8E\x88''\xF0\x9F\x98\x85''\xDF\xA6''\xE1\x8F\xA2''\xF0\x9F\x98\x8A' | xargs ./client 
*/
