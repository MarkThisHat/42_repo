/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:59:18 by maalexan          #+#    #+#             */
/*   Updated: 2022/11/02 23:20:54 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
typedef struct	s_node
{
	char			*scanned;
	unsigned int	amountnl;
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
	buffer = NULL;
	if (node.line)
	{
		free(node.line);
		printf("Freedit, node.amountl %i\n", node.amountnl);
		node.line = NULL;
	}
	if (node.amountnl)
	{
		if (ft_findnl(tptr, &node.scanned[node.liveindex]))
		{
			printf("findnl starts looking from here: %c<br>\n", node.scanned[node.liveindex]);
			node.line = ft_nodestrncpy(tptr, &node.scanned[node.liveindex], node.firstnl + 1);
			node.liveindex = node.firstnl + 1;
			node.length -= node.firstnl;
			node.amountnl--;
			//printf("Gotinside(node.amountnl is %i and node.length is %i)\n", node.amountnl, node.length);
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
		node.length = (unsigned int)read(fd, buffer, BUFFER_SIZE);
		if (!node.length)
			return (NULL); //reached eof
		ft_findnl(tptr, buffer);
		if (node.amountnl > 1)
			ft_recycle(tptr, buffer);
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
	free(buffer);
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (ft_freeptrs(ptr->scanned, ptr));
	newnode->length = (unsigned int)read(fd, buffer, BUFFER_SIZE);
	if (!newnode->length)
		return (NULL); //reached eof
	if (!ft_findnl(ptr, buffer))
	{
		newnode->line = ft_nodestrncpy(ptr, buffer, newnode->length);
		headptr->totalength += newnode->length;
		return (ft_chain(ptr, buffer, fd, headptr));
	}
	else
	{
		newnode->line = ft_nodestrncpy(ptr, buffer, newnode->firstnl + 1);
		headptr->totalength += newnode->length;
		headptr->line = (char *)malloc(sizeof(char) * (headptr->totalength + 1));
		if (!headptr->line)
			return (ft_freeptrs(buffer, headptr));
		headptr->line[headptr->totalength] = '\0';
		ft_bigcopy(headptr, headptr->line, &headptr->totalength);
		if (newnode->amountnl > 1)
		{
			headptr->amountnl = newnode->amountnl;
			ft_recycle(headptr, buffer);
		}
		return (newnode->line);
	}
}

void	ft_bigcopy(t_node *ptr, char *line, unsigned int *len)
{
	while (ptr->next)
		ft_bigcopy(ptr, line, len);
	while (ptr->length - 1)
	{
		line[*len--] = ptr->scanned[ptr->length];
		ptr->length--;
	}
}

void	ft_recycle(t_node *ptr, char *buffer)
{
	unsigned int	i;
	
	i = 0;
	ptr->amountnl--;
	ptr->scanned = (char *)malloc(sizeof(char) * ptr->length - ptr->firstnl);
	while (i < ptr->length - ptr->firstnl - 1)
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
