/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 03:05:52 by maalexan          #+#    #+#             */
/*   Updated: 2022/11/10 20:03:36 by maalexan         ###   ########.fr       */
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
	while (i < ptr->length)//could be a +1 here, cause it's index we are searching
	{
		if (buffer[i] == '\n')
		{
			found = 1;
			ptr->firstnl = i;
			ptr->hasnl = 1;
			return (found);
		}
		i++;
	}
	return (found);
}

char	*ft_freeptrs(char *c, t_node *ptr)
{
	while (ptr->next != NULL)
		(ft_freeptrs(ptr->scanned, ptr->next));
	if (c != NULL)
		free(c);
	if (ptr->next != NULL)
		free(ptr->next);
	return (NULL);
}
