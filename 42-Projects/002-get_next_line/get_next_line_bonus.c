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

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_node	node;
	char			*line;
	char			*buffer[1];

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0))
		return (NULL);
	*buffer = find_node(&node, fd);
	*buffer = create_buffer(fd, *buffer);
	if (!*buffer)
		return (NULL);
	line = create_line(*buffer);
	*buffer = refresh_buffer(*buffer);
	return (line);
}

char	*find_node(t_node *node, int fd)
{
	while (node->fd != fd && node->next)
		return (find_node(node->next, fd));
	if (fd == node->fd)
		return (node->buffer);
	node->next = create_node(node, fd);
	if (!node->next)
		return (NULL);
	return (find_node(node->next, fd));
}

char	*create_buffer(int fd, char *buffer)
{
	char	*temp;
	int		parsed;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	parsed = 1;
	while (!ft_strchr(buffer, '\n'))
	{
		parsed = read(fd, temp, BUFFER_SIZE);
		if (parsed < 1)
			break ;
		temp[parsed] = '\0';
		buffer = ft_strjoin(buffer, temp);
		if (!buffer)
		{
			free(temp);
			return (NULL);
		}
	}
	free(temp);
	return (buffer);
}

char	*create_line(char *buffer)
{
	char	*line;
	int		len;

	len = 0;
	if (!buffer[len])
		return (NULL);
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
	{
		line[len] = buffer[len];
		len++;
	}
	if (buffer[len] == '\n')
		line[len++] = '\n';
	line[len] = '\0';
	return (line);
}

char	*refresh_buffer(char *buffer)
{
	char	*new;
	int		len;

	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (!buffer[len])
	{
		free(buffer);
		return (NULL);
	}
	new = malloc(sizeof(char) * (ft_strlen(buffer) - len + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, &buffer[len + 1], (ft_strlen(&buffer[len + 1]) + 1));
	free(buffer);
	return (new);
}
