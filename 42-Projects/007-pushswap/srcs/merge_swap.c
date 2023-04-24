/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:29:18 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/23 16:58:39 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_arrays(t_merge_data *data, int n1, int n2)
{
	int	i;
	int	j;

	i = -1;
	while (++i < n1)
		data->l_half[i] = data->stack[data->left + i];
	j = -1;
	while (++j < n2)
		data->r_half[j] = data->stack[data->middle + 1 + j];
}

static void	merge_arrays(t_merge_data *data, int n1, int n2)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = data->left;
	while (i < n1 && j < n2)
	{
		if (data->l_half[i] <= data->r_half[j])
			data->stack[k] = data->l_half[i++];
		else
		{
			data->stack[k] = data->r_half[j];
			data->invers[k] = data->invers[data->middle + 1 + j] + (n1 - i);
			j++;
		}
		k++;
	}
	while (i < n1)
		data->stack[k++] = data->l_half[i++];
	while (j < n2)
		data->stack[k++] = data->r_half[j++];
}

static void	merge(t_merge_data *data)
{
	int	n1;
	int	n2;

	n1 = data->middle - data->left + 1;
	n2 = data->right - data->middle;
	data->l_half = malloc(n1 * sizeof(int));
	data->r_half = malloc(n2 * sizeof(int));
	fill_arrays(data, n1, n2);
	merge_arrays(data, n1, n2);
	free(data->l_half);
	free(data->r_half);
}

void	merge_sort(int *stack, int *invers, int left, int right)
{
	t_merge_data	data;

	if (left < right)
	{
		data.left = left;
		data.middle = left + (right - left) / 2;
		data.right = right;
		data.stack = stack;
		data.invers = invers;
		merge_sort(stack, invers, left, data.middle);
		merge_sort(stack, invers, data.middle + 1, right);
		merge(&data);
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

int	put_index(int *stack, int size, int n)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (stack[i] == n)
			break ;
		i++;
	}
	return (i);
}

void	set_index(t_item *item, int *stack, int size)
{
	item->i = put_index(stack, size, item->n);
	item = item->next;
	if (item)
		set_index(item, stack, size);
}

int	*pile_on(t_item *item, int size, int *invers)
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
	int *invers;
	
	invers = ft_calloc(size, sizeof(int));
	if (!invers)
		free_and_leave(head, 4);
	stack = pile_on(head, size, invers);
	merge_sort(stack, invers, 0, size - 1);
	if (!check_unique(stack, head, size, invers))
		leave_program("Error\n", 2);
	set_index(head, stack, size);
	ft_printf("Sorted array: \n");
	for (int i = 0; i < size; i++) {
		ft_printf("%d ", stack[i]);
	}
	ft_printf("\n");
	ft_printf("Inversions array: \n");
	for (int i = 0; i < size; i++) {
		ft_printf("%d ", invers[i]);
	}
	ft_printf("\n");
	free(invers);
	free(stack);
	return 0;
}
