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
		return (ft_eof(&node));
	if (!ft_findnl_and_recycle(tptr, buffer))
		return (ft_get_next_node(tptr, buffer, fd, &node));
	return (ft_nodestrncpy(tptr, buffer, tptr->firstnl + 1));
}

char	*ft_get_next_node(t_node *ptr, char *buffer, int fd, t_node *headptr)
{
	t_node	*newnode;

	newnode = malloc(sizeof(t_node));
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!newnode || !buffer)
		return (ft_freenodes(ptr));
	ptr->next = newnode;
	if (!ptr->i)
		newnode->length = (unsigned int)read(fd, buffer, BUFFER_SIZE);
	if (!headptr->chainsize)
		headptr->chainsize = headptr->length;
	headptr->chainsize += newnode->length;
	if (!newnode->length)
		return (ft_eof(headptr));
	if (!ft_findnl_and_recycle(ptr, buffer))
		return (ft_get_next_node(ptr, buffer, fd, headptr));
	return (ft_endcopy(headptr, newnode->scanned));
}

char	*ft_endcopy(t_node *ptr, char *buffer)
{
	ptr->line = (char *)malloc(sizeof(char) * (ptr->chainsize + 1));
	if (!ptr->line)
		return (ft_freenodes(ptr));
	ft_strncpy(ptr->line, ptr->scanned, ptr->length);
	free(ptr->scanned);
	if (buffer)
		ft_recycle(ptr, buffer);
	ptr->line[ptr->chainsize] = '\0';
	if (ptr->next)
		ft_bigcopy(ptr, ptr->line, &ptr->chainsize);
	ptr->chainsize = 0;
	return (ptr->line);
}

void	ft_bigcopy(t_node *ptr, char *line, unsigned int *len)
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
	free(ptr->scanned);
	free(ptr->next);
	ptr->next = NULL;
}

char	*ft_eof(t_node *ptr)
{
	if (!ptr->scanned && !ptr->line)
		return (ft_freenodes(ptr));
	if (ft_findnl_and_recycle(ptr, &ptr->scanned[ptr->i]))
		return (ft_nodestrncpy(ptr, ptr->scanned, ptr->firstnl + 1));
	return (ft_endcopy(ptr, NULL));
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
