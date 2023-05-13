/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:42:08 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/28 21:15:04 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_stack(t_item *a, int len, char **nbrs, t_item *past)
{
	static int	i;

	i++;
	a->prev = past;
	if (i < len)
	{
		a->n = ft_atoi(nbrs[i]);
		if (i != len - 1)
		{
			a->next = malloc(sizeof(t_item));
			if (!a->next)
				empty_stack(a, 4);
			*a->next = (t_item){0};
			fill_stack(a->next, len, nbrs, a);
		}
	}
}

static t_item	*stack_up(int argc, char **argv)
{
	t_item	*a;

	if (argc == 2)
		exit(0);
	a = malloc(sizeof(t_item) * argc);
	if (!a)
		exit(4);
	*a = (t_item){0};
	fill_stack(a, argc, argv, NULL);
	return (a);
}

int	main(int argc, char **argv)
{
	t_ctrl	c;

	if (argc < 2)
		return (1);
	check_args(argc, argv);
	c.head_a = stack_up(argc, argv);
	set_control(&c, c.head_a, argc - 1);
	assess_pile(c.head_a, argc - 1);
	if (is_sorted(&c))
		free_and_leave(&c, 0);
	find_sol(&c);
	free_and_leave(&c, 0);
}
