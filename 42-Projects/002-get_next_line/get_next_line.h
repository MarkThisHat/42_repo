/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 03:01:42 by maalexan          #+#    #+#             */
/*   Updated: 2022/11/02 23:21:24 by maalexan         ###   ########.fr       */
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
	unsigned int	amountnl;
	unsigned int	firstnl;
	unsigned int	liveindex;
	unsigned int	length;
	unsigned int	totalength;
	struct s_node	*next;
}	t_node;

char	*get_next_line(int fd);
char	*ft_freeptrs(char *c, t_node *ptr);
char	*ft_nodestrncpy(t_node *ptr, char *buffer, int n);
int		ft_findnl(t_node *ptr, char *buffer);
void	ft_recycle(t_node *ptr, char *buffer);
void	ft_bigcopy(t_node *ptr, char *line, unsigned int *len);
char	*ft_chain(t_node *ptr, char *buffer, int fd, t_node *headptr);

#endif