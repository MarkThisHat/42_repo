/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:27:20 by maalexan          #+#    #+#             */
/*   Updated: 2022/09/17 16:27:20 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	len;

	len = ft_strlen(s) + 1;
	if (len == 1)
		return (0);
	d = malloc(len);
	if (d != 0)
		d = ft_memcpy(d, s, len);
	return (d);
}
