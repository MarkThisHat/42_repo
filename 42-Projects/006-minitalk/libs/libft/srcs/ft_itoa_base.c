/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:43:54 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/13 16:52:59 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_len(int n, int base)
{
	int	len;

	len = 1;
	while (n / base)
	{
		len++;
		n /= base;
	}
	return (len);
}

static void	fill_in(char *r, int n, int based, int len)
{
	int	sign;

	if (based < 0)
	{
		based *= -1;
		sign = -1;
	}
	else
		sign = 1;
	while (len + 1)
	{
		if ((n % based) > 9)
			r[len] = ((n % based) * sign) + 55;
		else
			r[len] = ((n % based) * sign) + '0';
		n /= based;
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

char	*ft_itoa_base(int n, int base)
{
	char	*r;
	int		len;
	int		sign;

	r = NULL;
	if (!n || base < 2 || base > 36)
		return (itoa_zero(r));
	sign = 0;
	if (n < 0)
		sign = 1;
	len = find_len(n, base);
	if (sign)
		len++;
	r = malloc(sizeof(char) * (len + 1));
	r[len] = '\0';
	if (!sign)
		fill_in(r, n, base, len - 1);
	else
	{
		r[0] = '-';
		fill_in(&r[1], n, -base, len - 2);
	}
	return (r);
}
