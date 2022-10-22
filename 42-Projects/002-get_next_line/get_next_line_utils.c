/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 03:05:52 by maalexan          #+#    #+#             */
/*   Updated: 2022/10/22 18:18:16 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_copy(char *left, char *buff, char *line)
{
	int	i;

	i = 0;
	while ((buff[i]) && (buff[i] != '\n') && (i < BUFFER_SIZE))
	{
		*line = buff[i];
		line++;
		i++;
	}
	*line = '\0';
	while (buff[i] && i < BUFFER_SIZE)
	{
		*left = buff[i];
		left++;
		i++;
	}
	return (i);
}

int	ft_tilnextln(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] != '\n')
		i++;
	return (i++);
}
