/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 03:05:52 by maalexan          #+#    #+#             */
/*   Updated: 2022/11/20 15:02:15 by maalexan         ###   ########.fr       */
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

char	*ft_nodestrncpy(t_node *ptr, char *buffer, unsigned int n)
{
	char	*line;

	line = (char *)malloc(sizeof(char) * (n + 1));
	if (!line)
		return (ft_freeptrs(buffer, ptr));
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

char	*ft_freeptrs(t_node *ptr)
{
	while (ptr->next != NULL)
		(ft_freeptrs(ptr->next));
	if (ptr->scanned != NULL)
		free(ptr->scanned);
	if (ptr->line != NULL)
		free(ptr->line);
	if (ptr->next != NULL)
		free(ptr->next);
	return (NULL);
}
