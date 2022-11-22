/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 03:01:42 by maalexan          #+#    #+#             */
/*   Updated: 2022/11/22 18:48:31 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //REMOVE

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
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

char			*get_next_line(int fd);
char			*ft_get_next_node(t_node *ptr, char *buffer, int fd, t_node *headptr);
char			*ft_endcopy(t_node *ptr, char *buffer);
void			ft_bigcopy(t_node *ptr, char *line, unsigned int *len);
char			*ft_eof(t_node *ptr);
unsigned int	ft_findnl_and_recycle(t_node *ptr, char *buffer);
void			ft_recycle(t_node *tptr, char *buffer);
char			*ft_nodestrncpy(t_node *ptr, char *buffer, unsigned int n);
char			*ft_strncpy(char *d, char *s, unsigned int len);
char			*ft_freenodes(t_node *ptr);

#endif