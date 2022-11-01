/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:59:18 by maalexan          #+#    #+#             */
/*   Updated: 2022/11/01 03:09:46 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
typedef struct	s_node
{
	char			*scanned;
	unsigned int	amountnl;
	unsigned int	firstnl;
	unsigned int	length;
	struct s_node	*next;
}	t_node;*/

char	*get_next_line(int fd)
{
	static t_node	node;
	t_node			*tptr;
	char			*buffer;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	tptr = &node;
	if (node.line)
	{
		free(node.line);
		node.line = 0;
	}
	if (node.amountnl)
	{
		ft_findnl(tptr, node.scanned);
		node.line = ft_nodestrncpy(tptr, node.scanned, node.firstnl + 1);
		ft_recycle(tptr, node.scanned);
		return (node.line);
	}
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (ft_freeptrs(tptr->scanned, tptr));
	node.length = (unsigned int)read(fd, buffer, BUFFER_SIZE);
	if (!node.length)
		return (NULL);
	ft_findnl(tptr, buffer);
	if (node.firstnl < node.length)
		ft_recycle(tptr, buffer);
	//printf("node.firstnl: %i\nnode.length: %i, node.amountnl: %i\n", node.firstnl, node.length, node.amountnl);
	node.line = ft_nodestrncpy(tptr, buffer, node.firstnl + 1);
	return (node.line);
}

void	ft_recycle(t_node *ptr, char *buffer)
{
	int	i;
	int size;

	ptr->amountnl--;
	i = 0;
	size = ptr->length - ptr->firstnl;
	ptr->scanned = (char *)malloc(sizeof(char) * size);
	while (i < size - 1)
	{
		ptr->scanned[i] = buffer[i + ptr->firstnl + 1];
		i++;
	}
	ptr->scanned[i] = '\0';
	printf("len was %i ", ptr->length);
	ptr->length = i;
	printf("now is %i\n", ptr->length);
	//printf("scanned: %s\nI is %i and size is %i\nlen is %i\n", ptr->scanned, i, size, ptr->length);
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
	return (line);
}
