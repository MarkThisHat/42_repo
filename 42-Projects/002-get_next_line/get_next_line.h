/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 03:01:42 by maalexan          #+#    #+#             */
/*   Updated: 2022/11/20 14:59:54 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //REMOVE

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

typedef struct s_node
{
	char			*line;
	char			*scanned;
	unsigned int	i;
	unsigned int	hasnl;
	unsigned int	firstnl;
	unsigned int	length;
	unsigned int	chainsize;
	struct s_node	*next;
}	t_node;

char		*get_next_line(int fd);
char		*ft_freenodes(t_node *ptr);
char		*ft_get_next_node(t_node *ptr, int fd);
unsigned int ft_findnl_and_recycle(t_node *ptr, char *buffer)

#endif
