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

static int	ft_countp(char const *s, char c);
static int	ft_populate(const char *s, char c, char **pptr, int pointers);
static int	ft_section(const char *s, char **pptr, int len);
static char	**ft_bareparam(const char *s);

char	**ft_split(char const *s, char c)
{
	int		start;
	int		pointers;
	char	**pptr;

	if (!s || !c)
		return (ft_bareparam(s));
	start = 0;
	while (s[start] == c)
		start++;
	pointers = ft_countp(&s[start], c);
	if (!pointers)
		return (ft_bareparam(&s[start]));
	pptr = (char **)malloc(sizeof(pptr) * (pointers + 1));
	if (!pptr)
		return (NULL);
	pptr[0] = (char *)&s[start];
	if (!ft_populate(&s[start], c, pptr, pointers))
		return (NULL);
	pptr[pointers] = NULL;
	return (pptr);
}

static int	ft_countp(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
			s++;
		else
		{
			i++;
			while (*s == c)
				s++;
		}
	}
	if (i > 0 && *--s != c)
		i++;
	return (i);
}

static int	ft_section(const char *s, char **pptr, int len)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (0);
	while (len)
	{
		ptr[i] = s[i];
		len--;
		i++;
	}
	ptr[i] = '\0';
	*pptr = &ptr[0];
	return (1);
}

static int	ft_populate(const char *s, char c, char **pptr, int pointers)
{
	int	i;

	i = 0;
	while (pointers)
	{
		if (s[i] == c || !s[i])
		{
			if (!ft_section(s, pptr, i))
				return (0);
			pointers--;
			s += i;
			pptr++;
			i = 0;
			while (*s == c && *s)
				s++;
		}
		else
			i++;
	}
	return (1);
}

static char	**ft_bareparam(const char *s)
{
	char	**pptr;
	int		len;

	if (!s || !*s)
	{
		pptr = (char **)malloc(sizeof (pptr));
		if (!pptr)
			return (NULL);
		pptr[0] = NULL;
	}
	else
	{
		len = (int)ft_strlen(s) + 1;
		pptr = (char **)malloc(sizeof(pptr) * 2);
		pptr[0] = (char *)malloc(sizeof(char) * len);
		if (!pptr || !pptr[0])
			return (NULL);
		ft_strlcpy(pptr[0], s, len);
		pptr[1] = NULL;
	}
	return (pptr);
}
