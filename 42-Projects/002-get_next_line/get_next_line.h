/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 03:01:42 by maalexan          #+#    #+#             */
/*   Updated: 2022/11/25 17:36:06 by maalexan         ###   ########.fr       */
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
	int				i;
	int				hasnl;
	int				firstnl;
	int				length;
	int				chainsize;
	struct s_node	*next;
}	t_node;

char	*get_next_line(int fd);
char	*ft_get_next_node(t_node *ptr, char *buffer, int fd, t_node *headptr);
char	*ft_nodestrncpy(t_node *ptr, char *buffer, int n);
char	*ft_endcopy(t_node *ptr, t_node *lastnode);
char	*ft_eof(t_node *ptr);
char	*ft_strncpy(char *d, char *s, int len);
char	*ft_freenodes(t_node *ptr);
int		ft_findnl_and_recycle(t_node *ptr, char *buffer);
void	ft_recycle(t_node *ptr, char *buffer);
void	ft_bigcopy(t_node *ptr, char *line, int *len);

#endif