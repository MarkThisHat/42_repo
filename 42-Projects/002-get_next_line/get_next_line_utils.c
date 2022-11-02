/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 03:05:52 by maalexan          #+#    #+#             */
/*   Updated: 2022/11/02 23:20:04 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_findnl(t_node *ptr, char *buffer)
{
	unsigned int	i;
	int				found;

	i = 0;
	found = 0;
	ptr->firstnl = 0;
	while (i < ptr->length)
	{
		if (buffer[i] == '\n')
		{
			if (!found)
			{
				found = 1;
				ptr->firstnl = i;
				ptr->amountnl++;
				printf("Found my first nl at index %i\n", i);
			}
			else
			{
				ptr->amountnl++;
				return (found);
			}
		}
		i++;
	}
	return (found);
}

char	*ft_freeptrs(char *c, t_node *ptr)
{
	while (ptr->next)
		(ft_freeptrs(ptr->scanned, ptr->next));
	if (c)
		free(c);
	if (ptr->next)
		free(ptr->next);
	return (NULL);
}
