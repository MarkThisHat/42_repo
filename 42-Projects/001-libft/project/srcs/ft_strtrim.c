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
	int		start;
	int		end;

	start = 0;
	while (ft_seekchar(s1[start], set))
		start++;
	end = (int)ft_strlen(s1) - 1;
	if (!(start < end))
		return (ft_strdup("\0"));
	while (ft_seekchar(s1[end], set))
		end--;
	cpy = malloc(sizeof(char) * (end - start + 2));
	if (!cpy)
		return (NULL);
	ft_strlcpy(cpy, &s1[start], end - start + 2);
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
