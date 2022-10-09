/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:15:59 by maalexan          #+#    #+#             */
/*   Updated: 2022/09/07 20:15:59 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (n);
	i = 0;
	while (s1[i] == s2[i] && (i < n - 1) \
	&& (s1[i]) && (s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
