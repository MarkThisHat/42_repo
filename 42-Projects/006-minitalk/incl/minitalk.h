/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:23:27 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/13 16:52:30 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <sys/types.h>
# include <signal.h>
# include <unistd.h>
# include "../libs/libft/incl/libft.h"

extern volatile sig_atomic_t	g_andalf;

void	leave_program(char *str, int return_code);

#endif

/*
Testing emojis:
echo -e '\xDF\xB7''\xF0\x9F\x98\x80''\xC3\xB8''\xE1\x8E\x88'
'\xF0\x9F\x98\x85''\xDF\xA6''\xE1\x8F\xA2''\xF0\x9F\x98\x8A' | xargs ./client 
*/
