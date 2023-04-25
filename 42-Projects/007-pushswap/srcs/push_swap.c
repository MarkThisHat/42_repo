/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:42:08 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/24 21:02:27 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_item(t_item *item)
{
	ft_printf("%i\n", item->n);
	if (!item->next)
		return ;
	print_item(item->next);
}

void	print_detailed(t_item *item)
{
//	while (item->prev)
//		item = item->prev;
	ft_printf("\nCurrent: %i index: %i\n", item->n, item->i);
	if (item->next)
		ft_printf("Next: %i index: %i\n", item->next->n, item->next->i);
	if (item->prev)
		ft_printf("Previous: %i index: %i\n", item->prev->n, item->prev->i);
	if (!item->next)
		return ;
	print_detailed(item->next);
}

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
	t_item	*a;
	t_ctrl	c;

	if (argc < 2)
		return (1);
	check_args(argc, argv);
	a = stack_up(argc, argv);
	set_control(&c, a, argc - 1);
	assess_pile(c.head_a, argc - 1);
	print_detailed(c.head_a);
	ft_printf("testiong\n\n%i\n\n\n", c.size_a);
	rotate_a(&c);
	print_detailed(c.head_a);
	free_and_leave(c.head_a, 0);
}
