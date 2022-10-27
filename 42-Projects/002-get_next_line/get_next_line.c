/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:59:18 by maalexan          #+#    #+#             */
/*   Updated: 2022/10/26 22:22:11 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static t_keep	keep;
	t_keep			*tptr;
	char			*buff;
	int				size;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (!keep.saved && !keep.nlcount)
		size = (int)read(fd, buff, BUFFER_SIZE);
	if (!size)
		return (NULL);
	ft_find_count(tptr, buff, size);
	free(buff);
	return (tptr->line);
}

void	ft_find_count(t_keep *tptr, char *buff, int size)
{
	int	i;
	int	firstnl;

	i = 0;
	firstnl = 0;
	while (i < size)
	{
		if (buff[i] == '\n')
		{
			if (!firstnl)
				firstnl = i;
			tptr->nlcount++;
		}
		i++;
	}
	if (firstnl)
	{
		ft_copy(tptr, buff, firstnl);
		ft_save(tptr, &buff[firstnl], size - firstnl); //check math
	}
}

void	ft_copy(t_keep *tptr, char *buff, int firstnl)
{
	int	i;

	i = 0;
	tptr->nlcount--;
	if (tptr->line)
		free(tptr->line);
	tptr->line = (char *)malloc(sizeof(char) * (firstnl + 1)); //check math
	if (!tptr->line)
		return ;
	while (i < firstnl)
	{
		tptr->line[i] = buff[i];
		i++;
	}
	tptr->line[i] = '\0';
}

void	ft_save(t_keep *tptr, char *buff, int size)
{
	int	i;

	if (tptr->saved)
		free(tptr->saved);
	i = 0;
	tptr->saved = (char *)malloc(sizeof(char) * size);
	if (!tptr->saved)
		return ;
	while (i < size)
	{
		tptr->saved[i] = buff[i];
		i++;
	}
}
