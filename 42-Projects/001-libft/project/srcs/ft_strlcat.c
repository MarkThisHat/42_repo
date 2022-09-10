/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:01:16 by maalexan          #+#    #+#             */
/*   Updated: 2022/09/10 20:18:52 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(dst);
	if (len >= size || size == 0)
		return (size);
	while (src[i] != '\0' && len < size - 1)
	{
		dst[len] = src[i];
		i++;
		len++;
	}
	if (src[i] == '\0')
		dst[len] = '\0';
	else
		dst[len + 1] = '\0';
	return (len);
}
