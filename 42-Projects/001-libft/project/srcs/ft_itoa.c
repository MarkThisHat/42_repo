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

static int	ft_cdigits(int n);
static int	ft_powdigits(int len);
static void	ft_populate(char *itoa, int len, int n);

char	*ft_itoa(int n)
{
	char	*itoa;
	int		len;

	len = ft_cdigits(n);
	if (n < 0)
		len++;
	itoa = malloc(len + 1);
	if (!itoa)
		return (0);
	ft_populate(itoa, len, n);
	itoa[len] = '\0';
	return (itoa);
}

static void	ft_populate(char *itoa, int len, int n)
{
	int	i;
	int	digits;
	int	output;

	i = 0;
	digits = ft_powdigits(len);
	if (n < 0)
	{
		itoa[i] = '-';
		digits /= 10;
		n *= -1;
		i++;
	}
	while (i < len)
	{
		output = n / digits;
		itoa[i] = output + '0';
		n -= digits * output;
		digits = digits / 10;
		i++;
	}
}

static int	ft_cdigits(int n)
{
	if (n / 10 == 0)
		return (1);
	return (1 + ft_cdigits(n / 10));
}

static int	ft_powdigits(int len)
{
	int	digits;

	digits = 1;
	while (len > 1)
	{
		digits *= 10;
		--len;
	}
	return (digits);
}
