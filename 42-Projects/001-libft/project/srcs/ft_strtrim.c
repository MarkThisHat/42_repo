/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:01:28 by maalexan          #+#    #+#             */
/*   Updated: 2022/09/25 15:01:28 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_seekchar(char subs1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*cpy;
	size_t	start;
	size_t	end;

	start = 0;
	while (ft_seekchar(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (ft_seekchar(s1[end], set))
		end--;
	cpy = malloc(end - start + 1);
	if (!cpy)
		return (0);
	ft_strlcpy(cpy, s1, end - start + 1);
	return (cpy);
}

static int	ft_seekchar(char subs1, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == subs1)
			return (1);
		i++;
	}
	return (0);
}
