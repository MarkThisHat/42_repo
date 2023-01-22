/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:50:04 by maalexan          #+#    #+#             */
/*   Updated: 2022/09/18 16:50:04 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*d;
	unsigned int	i;
	unsigned int	size;

	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup("\0"));
	size = (unsigned int)ft_strlen(&s[start]);
	if (size < len)
		i = size + 1;
	else
		i = len + 1;
	d = malloc(sizeof(char) * i);
	if (!d)
		return (NULL);
	i = 0;
	while (i < len && i < size)
	{
		d[i] = s[start];
		i++;
		start++;
	}
	d[i] = '\0';
	return (d);
}
