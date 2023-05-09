/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_check_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:15:04 by maalexan          #+#    #+#             */
/*   Updated: 2023/05/09 10:12:26 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_sorted_bonus(t_ctrl *c)
{
	t_item	*ptr;

	if (c->size_b)
		return (0);
	ptr = c->head_a;
	while (ptr && ptr->next)
	{
		if (ptr->next->n < ptr->n)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int	check_duplicates(t_ctrl *c)
{
	t_item	*current;
	t_item	*temp;

	current = c->head_a;
	while (current)
	{
		temp = current->next;
		while (temp)
		{
			if (current->n == temp->n)
			{
				write(1, "Error\n", 6);
				free_and_leave(c, 1);
			}
			temp = temp->next;
		}
		current = current->next;
	}
	return (0);
}

int	mover_bonus(t_ctrl *c, char *line)
{
	if (!ft_strncmp("sa\n", line, 3))
		swap_a(c);
	else if (!ft_strncmp("sb\n", line, 3))
		swap_b(c);
	else if (!ft_strncmp("ss\n", line, 3))
		swap_both(c);
	else if (!ft_strncmp("pa\n", line, 3))
		push_a(c);
	else if (!ft_strncmp("pb\n", line, 3))
		push_b(c);
	else if (!ft_strncmp("ra\n", line, 3))
		rotate_a(c);
	else if (!ft_strncmp("rb\n", line, 3))
		rotate_b(c);
	else if (!ft_strncmp("rr\n", line, 3))
		rotate_both(c);
	else if (!ft_strncmp("rra\n", line, 4))
		rev_rotate_a(c);
	else if (!ft_strncmp("rrb\n", line, 4))
		rev_rotate_b(c);
	else if (!ft_strncmp("rrr\n", line, 4))
		rev_rotate_both(c);
	else
		return (0);
	return (1);
}
