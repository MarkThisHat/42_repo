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

void	fill_stack(t_item *a, int len, char **nbrs, t_item *past)
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
				free_and_leave(a, 4);
			*a->next = (t_item){0};
			fill_stack(a->next, len, nbrs, a);
		}
	}
}

t_item	*stack_up(int argc, char **argv)
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
	int		pivot;

	if (argc < 2)
		return (1);
	check_args(argc, argv);
	c.head_a = stack_up(argc, argv);
	set_control(&c, c.head_a, argc - 1);
	pivot = assess_pile(c.head_a, argc - 1);
	ft_printf("Pivot: %i\n", pivot);
	if (is_sorted(&c))
		free_and_leave(c.head_a, 0);
	sort_stack(&c, pivot, c.size_a);
	if (c.head_b)
		empty_stack(c.head_b);
	if (c.head_a)
		free_and_leave(c.head_a, 0);
	else
		return (0);
}
