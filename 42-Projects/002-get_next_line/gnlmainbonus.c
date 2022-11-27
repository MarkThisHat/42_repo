/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:27:25 by maalexan          #+#    #+#             */
/*   Updated: 2022/10/21 21:48:34 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>

int	main(int argc, char **argv)
{
	int	i;
	int	fd;
	int fd2;
	int fd3;
	(void)argc;
	(void)argv;
	fd = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	i = 1;
	while (i < 6)
	{
		printf("Gnl FIRST return %i: %s<-This should be at start line->\n", i, get_next_line(fd));
		printf("Gnl SECOND return %i: %s<-This should be at start line->\n", i, get_next_line(fd2));
		printf("Gnl THIRD return %i: %s<-This should be at start line->\n", i, get_next_line(fd3));
		i++;
	}
	close(fd);
	close(fd2);
	close(fd3);
	return (0);
}
