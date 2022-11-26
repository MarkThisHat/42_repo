/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 03:05:52 by maalexan          #+#    #+#             */
/*   Updated: 2022/11/26 13:23:38 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bigcopy(t_node *ptr, char *line, int *len)
{
	while (ptr->next != NULL && !ptr->hasnl)
	{
		ptr->hasnl = 1;
		ft_bigcopy(ptr->next, line, len);
	}
	while (ptr->length && !ptr->line)
	{
		*len -= 1;
		ptr->length--;
		line[*len] = ptr->scanned[ptr->length];
	}
	if (ptr->scanned)
		free(ptr->scanned);
	if (ptr->next)
		free(ptr->next);
	ptr->next = NULL;
}

char	*ft_eof(t_node *ptr)
{
	if (!ptr->scanned && !ptr->line)
		return (ft_freenodes(ptr));
	if (ft_findnl(ptr, &ptr->scanned[ptr->i]))
		return (ft_nodestrncpy(ptr, ptr->scanned, ptr->firstnl + 1));
	return (ft_endcopy(ptr, NULL));
}

char	*ft_nodestrncpy(t_node *ptr, char *buffer, int n)
{
	char	*line;

	line = (char *)malloc(sizeof(char) * (n + 1));
	if (!line)
		return (ft_freenodes(ptr));
	ft_strncpy(line, buffer, n);
	line[n] = '\0';
	return (line);
}

char	*ft_strncpy(char *d, char *s, int len)
{
	int	i;

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
