/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:42:08 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/23 16:07:27 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	empty_stack(t_item *item)
{
	t_item	*temp;
	
	while (item->prev)
		item = item->prev;
	while (item)
	{
		temp = item->next;
		free(item);
		item = temp;
	}
}

void	free_and_leave(t_item *stack, int return_code)
{
	empty_stack(stack);
	exit(return_code);
}

void	print_item(t_item *item)
{
	ft_printf("%i\n", item->n);
	if (!item->next)
		return ;
	print_item(item->next);
}

void	print_detailed(t_item *item)
{
	ft_printf("\nCurrent: %i\n", item->n);
	if (item->next)
		ft_printf("Next: %i\n", item->next->n);
	if (item->prev)
		ft_printf("Previous: %i\n", item->prev->n);
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
	t_item *a;

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
	t_item	*b;

	if (argc < 2)
		return (1);
	a = stack_up(argc, argv);
	check_args(argc, argv);
	print_item(a);
	print_detailed(a);
	free_and_leave(a, 0);
	(void)b;
}