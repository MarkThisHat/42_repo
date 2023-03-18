/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:32:38 by maalexan          #+#    #+#             */
/*   Updated: 2022/12/29 17:03:34 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static t_node	node_static[1];	
	t_node			node;
	char			*line;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (0);
	node = node_static[0];
	while (node.end < node.parsed && node.buffer[node.end] != '\n')
		node.end++;
	node.size = node.end - node.start;
	if (node.end < node.parsed)
	{
		node.size++;
		line = create_line(0, node.buffer + node.start, node.size, node.size);
		node.start = node.end + 1;
		node.end = node.start;
		node_static[0] = node;
	}
	else
	{
		line = read_fd(fd, node, node_static, node.size);
		free_node(&node);
	}
	return (line);
}

char	*create_line(char *line, char *append, int copy_amount, int size)
{
	if (size)
	{
		line = malloc(size + 1);
		if (line)
			line[size] = 0;
		size -= copy_amount;
	}
	if (line)
		while (copy_amount--)
			line[size++] = *append++;
	return (line);
}

char	*read_fd(int fd, t_node old, t_node *mod_new, int size)
{
	t_node		temp;
	char		*line;

	if (create_node(&temp, fd))
		return (0);
	if (temp.start > BUFFER_SIZE)
		line = read_fd(fd, old, mod_new, size + BUFFER_SIZE);
	else
	{
		line = create_line(0, temp.buffer, temp.size, size + temp.size);
		if (old.buffer)
			create_line(line, old.buffer + old.start, old.size, 0);
		*mod_new = temp;
		return (line);
	}
	if (line)
		create_line(line + size, temp.buffer, BUFFER_SIZE, 0);
	free_node(&temp);
	return (line);
}

int	create_node(t_node *node, int fd)
{
	node->start = 0;
	node->buffer = malloc(BUFFER_SIZE);
	if (!node->buffer)
		return (1);
	node->parsed = read(fd, node->buffer, BUFFER_SIZE);
	if (node->parsed < 1)
		free_node(node);
	if (node->parsed < 0)
		return (1);
	while (node->start < node->parsed && node->buffer[node->start] != '\n')
		node->start++;
	if (node->start < node->parsed)
		node->size = node->start + 1;
	else
		node->size = node->start;
	node->start++;
	node->end = node->start;
	return (0);
}

void	free_node(t_node *node)
{
	if (node->buffer)
		free(node->buffer);
	node->buffer = 0;
}
