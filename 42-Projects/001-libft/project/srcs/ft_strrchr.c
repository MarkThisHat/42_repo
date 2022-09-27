/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:22:46 by maalexan          #+#    #+#             */
/*   Updated: 2022/09/07 16:22:46 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	r;
	int	found;

	if (!c)
		return ((char *)&str[ft_strlen(str)]);
	i = 0;
	r = 0;
	found = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
		{
			r = i;
			found = 1;
		}
		i++;
	}
	if (r)
		return ((char *)&str[r]);
	if (!r && found)
		return ((char *)&str[r]);
	return (NULL);
}
