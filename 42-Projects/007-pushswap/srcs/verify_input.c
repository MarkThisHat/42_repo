/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:12:24 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/24 19:24:43 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_size(char *str)
{
	long	input;

	input = ft_atol(str);
	if (input > INT_MAX || input < INT_MIN)
		leave_program("Error\n", 2);
}

static void	check_digits(char *str)
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

int	check_unique(int *stack, t_item *item, int size, int *invers)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (stack[i] == stack[i + 1])
		{
			free(invers);
			free(stack);
			empty_stack(item);
			return (0);
		}
		i++;
	}
	return (1);
}
