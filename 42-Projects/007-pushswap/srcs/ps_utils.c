/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:23:57 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/18 20:30:57 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leave_program(char *str, int return_code)
{
	if (return_code == 0)
		exit (0);
	ft_putstr_fd(str, 2);
	exit (return_code);
}

void	check_size(char *str)
{
	long	input;
	
	input = ft_atol(str);
	if (input > INT_MAX || input < INT_MIN)
		leave_program("Error\n", 2);
}

void	check_digits(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			leave_program("Error\n", 3);
		str++;
	}
}

void	check_args(int argc, char **argv)
{
	while (argc > 1)
	{
		check_digits(argv[argc - 1]);
		check_size(argv[argc - 1]);
		argc--;
	}
}