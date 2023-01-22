/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:44:47 by maalexan          #+#    #+#             */
/*   Updated: 2022/09/26 14:44:47 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_cdigits(int n);
static int			ft_powdigits(int len, int n);
static void			ft_populate(char *itoa, unsigned int len, int n);

char	*ft_itoa(int n)
{
	char				*itoa;
	unsigned int		len;

	len = ft_cdigits(n);
	if (n < 0)
		len++;
	itoa = (char *)malloc(sizeof(char) * (len + 1));
	if (!itoa)
		return (NULL);
	ft_populate(itoa, len, n);
	itoa[len] = '\0';
	return (itoa);
}

static void	ft_populate(char *itoa, unsigned int len, int n)
{
	unsigned int	i;
	unsigned int	un;
	unsigned int	digits;
	unsigned int	singled;

	i = 0;
	digits = ft_powdigits(len, n);
	if (n < 0)
	{
		itoa[i] = '-';
		un = n * (-1);
		i++;
	}
	else
		un = n;
	while (i < len)
	{
		singled = un / digits;
		itoa[i] = singled + '0';
		un -= digits * singled;
		digits /= 10;
		i++;
	}
}

static unsigned int	ft_cdigits(int n)
{
	if (n / 10 == 0)
		return (1);
	return (1 + ft_cdigits(n / 10));
}

static int	ft_powdigits(int len, int n)
{
	int	digits;

	if (n < 0)
		len--;
	digits = 1;
	while (len > 1)
	{
		digits *= 10;
		--len;
	}
	return (digits);
}
