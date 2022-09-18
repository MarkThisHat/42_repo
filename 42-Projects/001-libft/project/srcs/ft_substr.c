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
	char	*ptr;
	size_t	i;

	if (!len)
		return (0);
	ptr = malloc(len + 1);
	if (ptr == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[i + (size_t)start];
		i++;
	}
	ptr[i++] = '\0';
	return (ptr);
}
