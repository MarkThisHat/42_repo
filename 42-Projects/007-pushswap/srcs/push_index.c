/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:18:01 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/24 19:27:13 by maalexan         ###   ########.fr       */
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

static int	*pile_on(t_item *item, int size, int *invers)
{
	int		i;
	int		*stack;

	stack = ft_calloc(size, sizeof(int));
	if (!stack)
	{
		free(invers);
		free_and_leave(item, 4);
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

int	assess_pile(t_item *head, int size)
{
	int	*stack;
	int	*invers;

	invers = ft_calloc(size, sizeof(int));
	if (!invers)
		free_and_leave(head, 4);
	stack = pile_on(head, size, invers);
	merge_sort(stack, invers, 0, size - 1);
	if (!check_unique(stack, head, size, invers))
		leave_program("Error\n", 2);
	set_index(head, stack, size);
	ft_printf("Sorted array: \n");
	for (int i = 0; i < size; i++)
		ft_printf("%d ", stack[i]);
	ft_printf("\n");
	ft_printf("Inversions array: \n");
	for (int i = 0; i < size; i++)
		ft_printf("%d ", invers[i]);
	ft_printf("\n");
	free(invers);
	free(stack);
	return (0);
}
