/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:59:18 by maalexan          #+#    #+#             */
/*   Updated: 2022/10/22 18:18:27 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*left;
	char		*buff;
	char		*line;
	int			linesize;
	
	buff = malloc(BUFFER_SIZE + 1);
	printf("Buffer size: %i\n", BUFFER_SIZE + 1);
	left = malloc(BUFFER_SIZE + 1);
	if (!buff || !left)
		return (NULL);
	read(fd, buff, BUFFER_SIZE);
	linesize = ft_tilnextln(buff);
	printf("Line size: %i\n", BUFFER_SIZE + 1);
	line = malloc(linesize + 1);
	ft_copy(left, buff, line);
	printf("Left is: %s\n", left);	
	return (line);
}
