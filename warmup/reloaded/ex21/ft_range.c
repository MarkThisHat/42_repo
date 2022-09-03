/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:37:57 by coder             #+#    #+#             */
/*   Updated: 2022/09/03 16:38:01 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	size;
	int	i;

	i = 0;
	array = 0;
	if (min >= max)
		return (array);
	size = max - min;
	array = malloc(size * sizeof(int));
	while (min < max)
	{
		array[i] = min;
		i++;
		min++;
	}
	return (array);
}
