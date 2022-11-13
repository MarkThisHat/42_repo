/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 03:05:52 by maalexan          #+#    #+#             */
/*   Updated: 2022/11/13 03:04:00 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_findnl(t_node *ptr, char *buffer)
{
	unsigned int	i;

	i = 0;
	ptr->hasnl = 0;
	ptr->firstnl = 0;
	while (i < ptr->length)
	{
		if (buffer[i] == '\n')
		{
			ptr->firstnl = i;
			ptr->hasnl = 1;
			return (ptr->hasnl);
		}
		i++;
	}
	return (ptr->hasnl);
}

char	*ft_nodestrncpy(t_node *ptr, char *buffer, int n)
{
	char	*line;
	int		i;

	line = (char *)malloc(sizeof(char) * (n + 1));
	if (!line)
		return (ft_freeptrs(buffer, ptr));
	i = 0;
	while (i < n)
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	/*free(*pbuffer);
	*pbuffer = NULL;*/
	return (line);
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
