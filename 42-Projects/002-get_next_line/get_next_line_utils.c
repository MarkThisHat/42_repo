/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 03:05:52 by maalexan          #+#    #+#             */
/*   Updated: 2022/11/23 19:26:07 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int	ft_findnl_and_recycle(t_node *ptr, char *buffer)
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
			if (ptr->length != (i + 1))
				ft_recycle(ptr, buffer);
			return (ptr->hasnl);
		}
		i++;
	}
	ft_recycle(ptr, buffer);
	return (ptr->hasnl);
}

void	ft_recycle(t_node *tptr, char *buffer)
{
	unsigned int	index;

	index = tptr->firstnl + tptr->hasnl;
	if (buffer == tptr->scanned)
	{
		tptr->i = tptr->firstnl + 1;
		return ;
	}
	tptr->scanned = (char *)malloc(sizeof(char) * tptr->length);
	if (!tptr->scanned)
	{
		tptr->hasnl = 2;
		return ;
	}
	ft_strncpy(tptr->scanned, &buffer[index], tptr->length);
	tptr->length -= index;
}

char	*ft_nodestrncpy(t_node *ptr, char *buffer, unsigned int n)
{
	char	*line;

	line = (char *)malloc(sizeof(char) * (n + 1));
	if (!line)
		return (ft_freenodes(ptr));
	ft_strncpy(line, buffer, n);
	line[n] = '\0';
	return (line);
}

char	*ft_strncpy(char *d, char *s, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

char	*ft_freenodes(t_node *ptr)
{
	while (ptr->next != NULL)
		(ft_freenodes(ptr->next));
	if (ptr->scanned != NULL)
		free(ptr->scanned);
	if (ptr->line != NULL)
		free(ptr->line);
	if (ptr->next != NULL)
		free(ptr->next);
	return (NULL);
}
