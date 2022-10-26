/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:59:18 by maalexan          #+#    #+#             */
/*   Updated: 2022/10/25 21:47:15 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*modget_next_line(int fd)
{
	static char	*left;
	char		*buff;
	char		*line;
	//char		**ptr;
	int			linesize;
	
	buff = malloc(BUFFER_SIZE + 1);
	buff[BUFFER_SIZE + 1] = '\0';
	/*ptr = &buff;
	if (!ft_smalloc(ptr, BUFFER_SIZE))
		return (NULL);*/
	left = malloc(BUFFER_SIZE + 1);
	left[BUFFER_SIZE + 1] = '\0';
	read(fd, buff, BUFFER_SIZE);
	linesize = ft_tilnextln(buff);
	line = malloc(linesize + 1);
	ft_copy(left, buff, line);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_keep	keep;
	t_keep			*tptr;
	char			*buff;
	int				size;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buff = (char)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (!keep.saved && !keep.nlcount)
		size = (int)read(fd, buff, BUFFER_SIZE);
	ft_tcharans(tptr, buff, size);

}

void	ft_tcharans(t_keep *tptr, char *buff, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		//do stuff
	}
}