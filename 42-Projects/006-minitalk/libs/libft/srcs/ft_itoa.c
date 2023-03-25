/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:43:54 by maalexan          #+#    #+#             */
/*   Updated: 2023/03/10 14:45:47 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_len(int n)
{
	int	len;

	len = 1;
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	fill_in(char *r, int n, int sign, int len)
{
	while (len + 1)
	{
		r[len] = ((n % 10) * sign) + '0';
		n /= 10;
		len--;
	}
}

static char	*itoa_zero(char *r)
{
	r = malloc(sizeof(char) * 2);
	r[0] = '0';
	r[1] = '\0';
	return (r);
}

char	*ft_itoa(int n)
{
	char	*r;
	int		len;
	int		sign;

	r = NULL;
	if (!n)
		return (itoa_zero(r));
	sign = 0;
	if (n < 0)
		sign = 1;
	len = find_len(n);
	if (sign)
		len++;
	r = malloc(sizeof(char) * (len + 1));
	r[len] = '\0';
	if (!sign)
		fill_in(r, n, 1, len - 1);
	else
	{
		r[0] = '-';
		fill_in(&r[1], n, -1, len - 2);
	}
	return (r);
}
