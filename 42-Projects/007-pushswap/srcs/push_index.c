/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:18:01 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/28 21:09:57 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	put_index(int *stack, int size, int n)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack[i] == n)
			break ;
		i++;
	}
	return (i);
}

static void	set_index(t_item *item, int *stack, int size)
{
	item->i = put_index(stack, size, item->n);
	item = item->next;
	if (item)
		set_index(item, stack, size);
}

static int	check_unique(int *stack, t_item *item, int size, int *invers)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (stack[i] == stack[i + 1])
		{
			free(stack);
			free(invers);
			empty_stack(item, 0);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	*pile_on(t_item *item, int size, int *invers)
{
	int		i;
	int		*stack;

	stack = ft_calloc(size, sizeof(int));
	if (!stack)
	{
		free(invers);
		empty_stack(item, 4);
	}
	i = 0;
	while (i < size)
	{
		stack[i] = item->n;
		item = item->next;
		i++;
	}
	return (stack);
}

void	assess_pile(t_item *head, int size)
{
	int	*stack;
	int	*invers;

	invers = ft_calloc(size, sizeof(int));
	if (!invers)
		empty_stack(head, 4);
	stack = pile_on(head, size, invers);
	merge_sort(stack, invers, 0, size - 1);
	if (!check_unique(stack, head, size, invers))
		leave_program("Error\n", 2);
	set_index(head, stack, size);
	free(invers);
	free(stack);
}
