/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:59:18 by maalexan          #+#    #+#             */
/*   Updated: 2022/11/11 23:37:34 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
typedef struct	s_node
{
	char			*scanned;
	unsigned int	hasnl;
	unsigned int	firstnl;
	unsigned int	liveindex;
	unsigned int	length;
	unsigned int	totalength; talvez seje desnecessário
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
		node.line = NULL;
	}
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (ft_freeptrs(tptr->scanned, tptr));
	if (node.scanned)
		return (ft_chain(tptr, buffer, fd, &node));
	node.length = (unsigned int)read(fd, buffer, BUFFER_SIZE);
	if (!node.length)
		return (NULL); //reached eof
	ft_findnl(tptr, buffer);
	if (node.hasnl && node.firstnl == node.length - 1) //node [0] [1] [2] [3] length = 4 node.firstnl = 3
		return (ft_nodestrncpy(tptr, buffer, node.firstnl + 1));
	ft_recycle(tptr, buffer);
	if (!node.firstnl)
		ft_chain(tptr, buffer, fd, &node);
	else
		node.line = ft_nodestrncpy(tptr, buffer, node.firstnl + 1);
	return (node.line);
}

char	*ft_chain(t_node *ptr, char *buffer, int fd, t_node *headptr)
{
	t_node *newnode;

	newnode = malloc(sizeof(t_node));
	if (!newnode)
		return (ft_freeptrs(buffer, ptr));
	newnode->next = NULL;
	newnode->line = NULL;
	ptr->next = newnode;
	if (!buffer)
		buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (ft_freeptrs(ptr->scanned, ptr));
	newnode->length = (unsigned int)read(fd, buffer, BUFFER_SIZE);
	if (!newnode->length)
		return (NULL); //reached eof
	headptr->length += newnode->length;
	if (!ft_findnl(newnode, buffer))
	{
		newnode->scanned = ft_nodestrncpy(newnode, buffer, newnode->length);
		return (ft_chain(newnode, buffer, fd, headptr));
	}
	newnode->scanned = ft_nodestrncpy(newnode, buffer, newnode->firstnl + 1);//could start copying and move this to later
	headptr->line = (char *)malloc(sizeof(char) * (headptr->length + 1));
	if (!headptr->line)
		return (ft_freeptrs(buffer, headptr));
	headptr->line[headptr->length] = '\0';
	ft_bigcopy(headptr, headptr->line, &headptr->length);
	return (headptr->line);
}

void	ft_bigcopy(t_node *ptr, char *line, unsigned int *len)
{
	while (ptr->next != NULL && !ptr->hasnl)
	{	
		ptr->hasnl = 1;//might have to changedis
		ft_bigcopy(ptr->next, line, len);
	}
	while (ptr->length && !ptr->line)
	{
		*len -= 1;
		ptr->length--;
		line[*len] = ptr->scanned[ptr->length];
		printf("line[%i] = %c\n", *len, line[*len]);
	}
	printf("%s\n", &line[*len]);
}

void	ft_recycle(t_node *ptr, char *buffer)
{
	unsigned int	i;
	unsigned int	size;
	
	i = 0;
	size = (ptr->length - ptr->firstnl - ptr->hasnl);//??  [0] [1] [n] [3] len 4 firstnl 2 1
	ptr->scanned = (char *)malloc(sizeof(char) * (size + 1));
	while (i < size)
	{
		ptr->scanned[i] = buffer[i + ptr->firstnl + ptr->hasnl];
		i++;
	}
	ptr->scanned[i] = '\0';
/*	if (ptr->length == i)
	{
		free(*pbuffer);
		*pbuffer = NULL;
	}
*/	ptr->length = i;
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
