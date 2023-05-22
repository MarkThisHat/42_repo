/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solc_extra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:31:21 by maalexan          #+#    #+#             */
/*   Updated: 2023/05/22 09:53:37 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int calc_same_pile(t_item *item, int target)
{
	int i;

	i = 0;
	while (item)
	{
		if (target = item->i - 1)
			return (i);
		item = item->next;
		i++;
	}
	return (-1);
}