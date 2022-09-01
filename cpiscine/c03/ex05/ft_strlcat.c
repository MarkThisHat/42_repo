/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:50:48 by maalexan          #+#    #+#             */
/*   Updated: 2022/07/27 11:53:08 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;
	unsigned int	d_len;

	i = 0;
	len = 0;
	while (dest[len] != '\0')
		len++;
	if ((size < 1) || (len < 1))
		return (size * len);
	while (src[i] != '\0' && i < size - 1)
	{
		dest[len] = src[i];
		len++;
		i++;
	}
	dest[len] = '\0';
	d_len = len;
	while (src[i] != '\0')
	{
		d_len++;
		i++;
	}
	return (d_len);
}
