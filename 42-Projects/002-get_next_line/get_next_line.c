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
		buffer = &tptr->scanned[tptr->i];
	if (!buffer)
		return (ft_freenodes(&node));
	if (!tptr->length)
		tptr->length = (int)read(fd, buffer, BUFFER_SIZE);
	if (!tptr->length)
		return (ft_eof(&node));
	if (!ft_findnl(tptr, buffer))
		return (ft_get_next_node(tptr, buffer, fd, &node));
	/*if (!(tptr->length - tptr->firstnl - tptr->hasnl))
		free(buffer);*/
	node.line = ft_nodestrncpy(tptr, buffer, tptr->firstnl + 1);
	return (node.line);
}

int	ft_recycle(t_node *ptr, char *buffer, char *recycled)
{
	int	len;

	len = ptr->length - ptr->firstnl - ptr->hasnl;
	if (len < 1)
		return (1);
	recycled = (char *)malloc(sizeof(char) * len);
	if (recycled)
		return (0);
	if (ft_strncpy(recycled, buffer, len))
		return (len);
	return (0);
}

int	ft_findnl(t_node *ptr, char *buffer)
{
	int	i;

	i = 0;
	ptr->hasnl = 0;
	ptr->firstnl = 0;
	while (i < ptr->length)
	{
		if (buffer[i] == '\n')
		{
			ptr->firstnl = i;
			ptr->hasnl = 1;
			if (ptr->length > (i + 1))
				ptr->i += i + 1;
			return (ptr->hasnl);
		}
		i++;
	}
	return (ptr->hasnl);
}

char	*ft_get_next_node(t_node *ptr, char *buffer, int fd, t_node *headptr)
{
	t_node	*newnode;

	if (!ft_recycle(ptr, buffer, ptr->scanned))
		return (ft_freenodes(headptr));
	newnode = malloc(sizeof(t_node));
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!newnode || !buffer)
		return (ft_freenodes(headptr));
	ptr->next = newnode;
	newnode->next = NULL;
	newnode->line = NULL;
	newnode->scanned = NULL;
	newnode->length = (int)read(fd, buffer, BUFFER_SIZE);
	if (!headptr->chainsize)
		headptr->chainsize = headptr->length;
	headptr->chainsize += newnode->length;
	if (!newnode->length)
		return (ft_eof(headptr));
	if (!ft_findnl(newnode, buffer))
		return (ft_get_next_node(newnode, buffer, fd, headptr));
	return (ft_endcopy(headptr, newnode));
}

char	*ft_endcopy(t_node *ptr, t_node *lastnode)
{
	ptr->line = (char *)malloc(sizeof(char) * (ptr->chainsize + 1));
	if (!ptr->line)
		return (ft_freenodes(ptr));
	ft_strncpy(ptr->line, ptr->scanned, ptr->length);
	ptr->line[ptr->chainsize] = '\0';
	free(ptr->scanned);
	ptr->scanned = NULL;
	ptr->i = 0;
	if (ptr != lastnode && lastnode->scanned)
	{
		if (!ft_recycle(lastnode, lastnode->scanned, ptr->scanned))
			return (ft_freenodes(ptr));
		ptr->length = lastnode->length;
	}
	if (ptr->next)
		ft_bigcopy(ptr, ptr->line, &ptr->chainsize);
	ptr->chainsize = 0;
	return (ptr->line);
}


	/*		len = 3
	*	if !fnl [a] [b] [c]
	*		recicla (len - fnl - hasnl)
	*
		chain
	*/
	/*		len = 3 fnl 2 hasnl 1	recicla nada (pode botar um if !scanned, ptr->scanned = buff)
			[a] [b] [n]
	*	if fnl + hasnl == len
	*		copia linha, limpa tudo, retorna linha
	*
	*/
	/*
	*	else
			len 6
			fnl 3
			hnl 1
			[a] [b] [c] [n] [d] [e]
			(char *)malloc(sizeof(char) * ptr->length - ptr->firstnl - ptr->hasnl);
	*		recicla (len - fnl - hasnl) 6 - 3 - 1
	*		copia linha
	*		limpa tudo
	*		retorna linha
	*
	*/
/* if (tptr->firstnl + tptr->hasnl == tptr->length) */