/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:59:18 by maalexan          #+#    #+#             */
/*   Updated: 2022/10/28 01:42:09 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_copy(char *left, char *buff, t_rack *ints);
int	ft_findnl(char *ptr, t_rack	*ints);

char	*get_next_line(int fd)
{
	static char	*left;
	char		*buff;
	t_rack		log;
	t_rack		*ints;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buff)
		return (NULL);
	if (!left)
		log.size = read(fd, buff, BUFFER_SIZE);
	if (!log.size)
		return (NULL);
	ints = &log;
	if (ft_findnl(buff, ints))
		return (ft_copy(left, buff, ints));
	return (0);
}

int	ft_findnl(char *ptr, t_rack	*ints)
{
	ints->i = 0;
	ints->nl = 0;
	while (ints->i < ints->size)
	{
		if (ptr[ints->i] == '\n')
			ints->nl = ints->i + 1;
		ints->i++;
	}
	printf("ints nl in findnl %i\n", ints->nl);
	return (ints->nl);
}

char	*ft_copy(char *left, char *buff, t_rack *ints)
{
	printf("ints->i is %i\nints->nl is %i\n", ints->i, ints->nl);
	printf("buff is %s\n", buff);
	free (buff);
	return (left);
}
