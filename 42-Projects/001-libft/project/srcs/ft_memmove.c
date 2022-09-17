/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:48:51 by maalexan          #+#    #+#             */
/*   Updated: 2022/09/15 20:48:51 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if (src + n >= dest)
	{
		src += n;
		dest += n;
		while (n--)
			*d-- = *s--;
		return (dest);
	}
	return (ft_memcpy(dest, src, n));
}

	/*
	VLA?
	unsigned char	temp[n];
	ft_memcpy(temp, src, n);
	ft_memcpy(dest, temp, n);
	return (dest);
	*/