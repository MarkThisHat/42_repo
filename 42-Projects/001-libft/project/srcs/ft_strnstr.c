/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:17:05 by maalexan          #+#    #+#             */
/*   Updated: 2022/09/07 21:17:05 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	i;
	size_t	b;

	if (!*little)
		return ((char *)big);
	b = 0;
	while (b < len && *big)
	{
		if (*big == *little)
		{
			i = 1;
			while (little[i] == big[i] && b + i < len)
				i++;
			if (!little[i])
				return ((char *)big);
		}
		b++;
		big++;
	}
	return (NULL);
}
