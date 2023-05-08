/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:12:24 by maalexan          #+#    #+#             */
/*   Updated: 2023/05/08 17:05:00 by maalexan         ###   ########.fr       */
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

int	is_sorted(t_ctrl *c)
{
	t_item	*ptr;

	if (c->size_b)
		return (0);
	ptr = c->head_a;
	while (ptr && ptr->next)
	{
		if (ptr->next->i < ptr->i)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}
