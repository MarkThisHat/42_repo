/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:59:18 by maalexan          #+#    #+#             */
/*   Updated: 2022/11/25 21:39:23 by maalexan         ###   ########.fr       */
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
		buffer = &tptr->scanned[tptr->i];//tptr->length -= tptr->i;
	if (!buffer)
		return (ft_freenodes(&node));
	if (!tptr->length)
		tptr->length = (int)read(fd, buffer, BUFFER_SIZE);
	if (!tptr->length)
		return (ft_eof(&node));
	if (!ft_findnl_and_recycle(tptr, buffer))
		return (ft_get_next_node(tptr, buffer, fd, &node));
	/*if (!(tptr->length - tptr->firstnl - tptr->hasnl))
		free(buffer);*/
	node.line = ft_nodestrncpy(tptr, buffer, tptr->firstnl + 1);
	return (node.line);
}

int	ft_findnl_and_recycle(t_node *ptr, char *buffer)
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
			/*if (ptr->length > (i + 1))
				ptr->i = i + 1;*/
			break;
		}
		i++;
	}
	i = ptr->length - ptr->firstnl - ptr->hasnl;
	if (i > 0)
		ptr->length = i;
	if (!ptr->scanned && i)
		ptr->scanned = (char *)malloc(sizeof(char) * ptr->length);
	if (!ptr->scanned)
		return (-1);
	ft_recycle(ptr, buffer);
	return (ptr->hasnl);
}

char	*ft_get_next_node(t_node *ptr, char *buffer, int fd, t_node *headptr)
{
	t_node	*newnode;

	newnode = malloc(sizeof(t_node));
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!newnode || !buffer)
		return (ft_freenodes(ptr));
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
	if (!ft_findnl_and_recycle(newnode, buffer))
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
	ptr->i = 0;
	ptr->scanned = NULL;
	if (ptr != lastnode && lastnode->scanned != NULL)
	{
		lastnode->i = lastnode->length - lastnode->firstnl - 1;
		if (lastnode->i > 0)
		{
			ptr->scanned = malloc(sizeof(char) * lastnode->i);
			if (!ptr->scanned)
				return (ft_freenodes(ptr));
			ft_strncpy(ptr->scanned, &lastnode->scanned[lastnode->firstnl + 1], lastnode->i);
		}
	}
	if (ptr->next)
		ft_bigcopy(ptr, ptr->line, &ptr->chainsize);
	ptr->chainsize = 0;
	return (ptr->line);
}

void	ft_recycle(t_node *ptr, char *buffer)
{
	int	len;

	len = ptr->length - ptr->firstnl - ptr->hasnl;
	if (len < 0)
		return ;
	if (ptr->length > ptr->firstnl + 1 && ptr->hasnl)
		ptr->i += len;
	ft_strncpy(ptr->scanned, &buffer[ptr->i], len);
	ptr->length = len;
}

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
	if (ft_findnl_and_recycle(ptr, &ptr->scanned[ptr->i]))
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