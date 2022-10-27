/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 03:01:42 by maalexan          #+#    #+#             */
/*   Updated: 2022/10/26 21:15:24 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_tracker
{
	char	*saved;
	char	*line;
	int		nlcount;
	int		booleon;
}	t_keep;

char	*get_next_line(int fd);
int		ft_tilnextln(char *buff);
int		ft_smalloc(char **c, int i);
int		ft_oldcopy(char *left, char *buff, char *line);

#endif