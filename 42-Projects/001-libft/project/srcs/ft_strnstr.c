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
	size_t	len_l;
	size_t	len_b;

	i = 0;
	if (len == 0)
		return (0);
	len_l = ft_strlen(little);
	len_b = ft_strlen(big);
	if (len_l == 0)
		return ((char *)&big[i]);
	while ((i <= len_b - len_l) && (i <= len - len_l))
	{
		if (big[i] == little[0])
			if (ft_strncmp(&big[i], &little[0], len_l) == 0)
				return ((char *)&big[i]);
		i++;
	}
	return (0);
}
