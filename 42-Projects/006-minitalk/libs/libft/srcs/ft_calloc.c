/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:22:59 by maalexan          #+#    #+#             */
/*   Updated: 2022/09/17 16:22:59 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmb, size_t size)
{
	void	*ptr;

	if (nmb * size == 0 || size > INT_MAX / nmb)
		return (NULL);
	ptr = malloc(nmb * size);
	if (ptr)
		ft_bzero(ptr, nmb * size);
	return (ptr);
}
