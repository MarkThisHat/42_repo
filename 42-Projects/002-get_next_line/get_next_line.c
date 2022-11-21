/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:59:18 by maalexan          #+#    #+#             */
/*   Updated: 2022/11/21 18:04:53 by maalexan         ###   ########.fr       */
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
	if (node.line)
		free(node.line);
	tptr = &node;
	if (!tptr->scanned)
		buffer = malloc(sizeof(char) * BUFFER_SIZE);
	else
		buffer = tptr->scanned;
	if (!buffer)
		return (ft_freenodes(&node));
	if (!tptr->length)
		tptr->length = (unsigned int)read(fd, buffer, BUFFER_SIZE);
	if (!tptr->length)
		return (ft_eof());
	if (!ft_findnl_and_recycle(tptr, buffer))
		return (ft_get_next_node(tptr, fd, &node));
	return (ft_nodestrncpy(tptr, buffer, tptr->firstnl + 1));
}

char	*ft_get_next_node(t_node *ptr, char *buffer, int fd, t_node *headptr)
{
	t_node *newnode;

	newnode = malloc(sizeof(t_node));
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!newnode || !buffer)
		return (ft_freeptrs(ptr));
	ptr->next = newnode;
	newnode->length = (unsigned int)read(fd, buffer, BUFFER_SIZE);
	if (!newnode->length)
		return (ft_eof());
		headptr->chainsize += newnode->length;
	if (!ft_findnl_and_recycle(ptr, buffer))
		return (ft_get_next_node(ptr, fd, headptr));
	headptr->line = (char *)malloc(sizeof(char) * (headptr->chainsize + 1));
	if (!headptr->line)
		return (ft_freeptrs(buffer, headptr));
	ft_strncpy(headptr->line, headptr->scanned, headptr->length);
	free(headptr->scanned);
	headptr->scanned = NULL;//have to copy what's left after \n to here
	headptr->line[headptr->chainsize] = '\0';
	ft_bigcopy(headptr, headptr->line, &headptr->chainsize);
	headptr->chainsize = 0;
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
	}
}

unsigned int ft_findnl_and_recycle(t_node *ptr, char *buffer)
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
	return (ptr->hasnl);
}

void	ft_recycle(t_node *tptr, char *buffer)
{
	unsigned int	index;

	index = tptr->firstnl + tptr->hasnl;
	tptr->length -= index;
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
	ft_strncpy(tptr->scanned, &buffer[index] , tptr->length);
}
	/*
	*	if !fnl 
	*		recicla (len - fnl - hasnl)
	*	
		chain
	*/
	/*
	*	if fnl + hasnl == len
	*		copia linha, limpa tudo, retorna linha
	*
	*/
	/*
	*	else
	*		recicla (len - fnl - hasnl)
	*		copia linha
	*		limpa tudo
	*		retorna linha
	*
	*/
/* if (tptr->firstnl + tptr->hasnl == tptr->length) */