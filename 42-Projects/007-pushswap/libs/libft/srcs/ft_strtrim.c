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

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*cpy;
	int		start;
	int		end;

	start = 0;
	while (ft_strchr(set, s1[start]))
		start++;
	end = (int)ft_strlen(s1) - 1;
	if (!(start < end))
		return (ft_strdup("\0"));
	while (ft_strchr(set, s1[end]))
		end--;
	cpy = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!cpy)
		return (NULL);
	ft_strlcpy(cpy, &s1[start], end - start + 2);
	return (cpy);
}
