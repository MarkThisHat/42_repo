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
#include <stdint.h>

void	*ft_calloc(size_t nmb, size_t size)
{
	void	*ptr;

	if (nmb * size == 0 || (nmb == SIZE_MAX && size == SIZE_MAX))
		return (NULL);
	ptr = malloc(nmb * size);
	if (ptr != 0)
		ft_bzero(ptr, nmb * size);
	return (ptr);
}
