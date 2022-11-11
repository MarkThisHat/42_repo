/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:59:18 by maalexan          #+#    #+#             */
/*   Updated: 2022/11/10 20:15:08 by maalexan         ###   ########.fr       */
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
	unsigned int	totalength;
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
	buffer = NULL;//?
	if (node.line)
	{
		free(node.line);
		node.line = NULL;
	}
	if (node.hasnl) //commented node.hasnl to try and fix the mistake
	{
		node.hasnl--;
		if (ft_findnl(tptr, &node.scanned[node.liveindex]))
		{
			node.line = ft_nodestrncpy(tptr, &node.scanned[node.liveindex], node.firstnl + 1);
			node.liveindex = node.firstnl + 1;
			node.length -= node.firstnl;
			node.hasnl--;
			return (node.line);
		}
		else
			return (ft_chain(tptr, buffer, fd, &node));
	}
	//experimental else:
	else
	{
		buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		if (!buffer)
			return (ft_freeptrs(tptr->scanned, tptr));
		node.length = (unsigned int)read(fd, buffer, BUFFER_SIZE);//make sure node.length is zero b4 doing read
		if (!node.length)
			return (NULL); //reached eof
		ft_findnl(tptr, buffer);
		if (node.firstnl < node.length)//problem if no nl found, likely add an if on line 68
			ft_recycle(tptr, buffer);
		if (!node.firstnl)
			return (ft_chain(tptr, buffer, fd, &node));
		node.line = ft_nodestrncpy(tptr, buffer, node.firstnl + 1);
		return (node.line);
	}
	return ("Hehehe");
	//end experiment
}

char	*ft_chain(t_node *ptr, char *buffer, int fd, t_node *headptr)
{
	t_node *newnode;

	newnode = malloc(sizeof(t_node));
	if (!newnode)
		return (ft_freeptrs(buffer, ptr));
	newnode->next = NULL;
	ptr->next = newnode;
	if (!headptr->totalength)
		headptr->totalength = headptr->length;
	newnode->hasnl = 1;//?
	if (!buffer)
		buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (ft_freeptrs(ptr->scanned, ptr));
	newnode->length = (unsigned int)read(fd, buffer, BUFFER_SIZE);
	if (!newnode->length)
		return (NULL); //reached eof
	if (!ptr->firstnl)
	{
		if (!ft_findnl(ptr, buffer))
		{
			newnode->line = ft_nodestrncpy(newnode, buffer, newnode->length);
			headptr->totalength += newnode->length;
			return (ft_chain(headptr, buffer, fd, headptr));
		}
	}
	newnode->scanned = ft_nodestrncpy(newnode, buffer, newnode->firstnl + 1);
	headptr->totalength += newnode->length;
	headptr->hasnl = 1;//?????
	headptr->line = (char *)malloc(sizeof(char) * (headptr->totalength + 1));
	if (!headptr->line)
		return (ft_freeptrs(buffer, headptr));
	headptr->line[headptr->totalength] = '\0';
	ft_bigcopy(headptr, headptr->line, &headptr->totalength);
	/*if (newnode->hasnl > 1)
	{
		headptr->hasnl = newnode->hasnl;
		ft_recycle(headptr, buffer);
	}*/
	return (newnode->line);
}

void	ft_bigcopy(t_node *ptr, char *line, unsigned int *len)
{
	while (ptr->next != NULL && !ptr->hasnl)
	{	
		ptr->hasnl = 0;//might have to changedis
		ft_bigcopy(ptr->next, line, len);
	}
	while (ptr->length)
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
	size = (ptr->length - ptr->firstnl - ptr->hasnl);
	//ptr->hasnl--; making messes here firstnl = 0  length = 5 [0] [1] [2] [3] [4] (5 + 0 + 1 + 1)
	ptr->scanned = (char *)malloc(sizeof(char) * (size + 1));//has to be at least 2 here
	while (i < size)
	{
		ptr->scanned[i] = buffer[i + ptr->firstnl + ptr->hasnl];
		i++;
	}
	ptr->scanned[i] = '\0';
	if (ptr->length == i)
	{
		free(buffer);
		buffer = NULL;
	}
	ptr->length = i;
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
	free(buffer);
	buffer = NULL;//não adianta dar free na cópia do ponteiro
	return (line);
}
