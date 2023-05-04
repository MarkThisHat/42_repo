/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:29:18 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/24 19:13:30 by maalexan         ###   ########.fr       */
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
