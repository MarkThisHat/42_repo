/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:40:49 by maalexan          #+#    #+#             */
/*   Updated: 2022/09/25 16:40:49 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_populaterer(const char *s, char c, char *ptr, char **pptr);

char	**ft_split(char const *s, char c)
{
	char	*starter;
	char	**pointerer;
	size_t	len;
	size_t	splitr;

	len = 0;
	splitr = 0;
	while (s[len] != '\0')
	{
		if (s[len] == c)
			splitr++;
		len++;
	}
	starter = malloc(len);
	pointerer = malloc(sizeof(starter) * splitr);
	if (!starter || !pointerer || len == 0)
		return (0);
	pointerer = &starter;
	ft_populaterer(s, c, starter, pointerer);
	pointerer[splitr] = 0;
	return (pointerer);
}

static void	ft_populaterer(const char *s, char c, char *ptr, char **pptr)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			*ptr = '\0';
			pptr++;
			*pptr = ptr++;
		}
		else
			*ptr = *s;
		s++;
		ptr++;
	}
}

/*
aaaZ    bbbZ    ccc'\0'
aaa'\0' bbb'\0' ccc'\0'
*/