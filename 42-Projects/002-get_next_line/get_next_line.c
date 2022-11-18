/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:59:18 by maalexan          #+#    #+#             */
/*   Updated: 2022/11/17 21:13:15 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (node.scanned)
	{
		buffer = node.scanned;
		if(!ft_findnl(tptr, node.scanned))//use findnl with node.scanned instead of buffer
		{
			buffer = malloc(sizeof(char) * (node.length));
			unsigned int i = 0;
			while (i < node.length)
			{
				buffer[i] = node.scanned[i];
				i++;
			}
			return (ft_chain(tptr, buffer, fd, &node));
		}
		if (buffer[node.length - 1] == '\n' && (&buffer[node.length - 1] == &buffer[node.firstnl])) //node [0] [1] [2] [3] length = 4 node.firstnl = 3
			return (ft_nodestrncpy(tptr, buffer, node.firstnl + 1));
		ft_recycle(tptr, buffer);
		if (!node.firstnl)
			ft_chain(tptr, buffer, fd, &node);
		else
			node.line = ft_nodestrncpy(tptr, buffer, node.firstnl + 1);
		return (node.line);
	}
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (ft_freeptrs(tptr->scanned, tptr));
	node.length = (unsigned int)read(fd, buffer, BUFFER_SIZE);
	if (!node.length)
		return (NULL); //reached eof
	ft_findnl(tptr, buffer);
	if (node.hasnl && node.firstnl == node.length - 1) //node [0] [1] [2] [3] length = 4 node.firstnl = 3
	{
		node.line = ft_nodestrncpy(tptr, buffer, node.firstnl + 1);
		free(node.scanned);
		node.scanned = NULL;
		return (node.line);
	}
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
	newnode->chainsize = 0;
	ptr->next = newnode;
	if (!buffer)
		buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (ft_freeptrs(ptr->scanned, ptr));
	newnode->length = (unsigned int)read(fd, buffer, BUFFER_SIZE);
	if (!newnode->length)
		return (NULL); //reached eof
	if (!headptr->chainsize)
		headptr->chainsize += headptr->length;
	headptr->chainsize += newnode->length;
	if (!ft_findnl(newnode, buffer))
	{
		newnode->scanned = ft_nodestrncpy(newnode, buffer, newnode->length);
		return (ft_chain(newnode, buffer, fd, headptr));
	}
	newnode->scanned = ft_nodestrncpy(newnode, buffer, newnode->firstnl + 1);//good job marcos do passado!| copia o resto pro headptr->scanned mas como saber o tamanho?
	headptr->line = (char *)malloc(sizeof(char) * (headptr->chainsize + 1));
	if (!headptr->line)
		return (ft_freeptrs(buffer, headptr));
	while (headptr->length)
	{
		headptr->length--;
		headptr->line[headptr->length] = headptr->scanned[headptr->length];
	}
	free(headptr->scanned);
	headptr->scanned = malloc(sizeof(char) * newnode->length - newnode->firstnl);//might need an if here
	if (!headptr->scanned)
		return (ft_freeptrs(buffer, headptr));
	unsigned int i = 0;
	while (i < newnode->length - newnode->firstnl + 1)
	{
		headptr->scanned[i] = buffer[i + newnode->firstnl + newnode->hasnl];
		i++;
	}
	headptr->scanned[i] = '\0';
	headptr->length = i - 1;
	headptr->line[headptr->chainsize] = '\0';
	ft_bigcopy(headptr, headptr->line, &headptr->chainsize);//gotta free some stuff here and zero sum statics
	//printf("Without the newline: %s<-there will be a new line here\n", headptr->line);
	return (headptr->line);
}

void	ft_bigcopy(t_node *ptr, char *line, unsigned int *len)
{
	while (ptr->next != NULL && !ptr->hasnl)
	{	
		ptr->hasnl = 1;//might have to changedis, or not
		ft_bigcopy(ptr->next, line, len);
	}
	while (ptr->length && !ptr->line)
	{
		*len -= 1;
		ptr->length--;
		line[*len] = ptr->scanned[ptr->length];
		//printf("line[%i] = %c\n", *len, line[*len]);
	}
	//printf("%s\n", &line[*len]);
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
	ptr->length = i;
}
