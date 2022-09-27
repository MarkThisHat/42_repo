/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:51:21 by maalexan          #+#    #+#             */
/*   Updated: 2022/09/27 11:51:21 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_ptendigits(unsigned int d);

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	digits;
	unsigned int	un;
	unsigned int	singled;

	if (n < 0)
	{
		un = n * (-1);
		ft_putchar_fd('-', fd);
	}
	else
		un = n;
	digits = ft_ptendigits(un);
	while (digits > 1)
	{
		singled = un / digits;
		ft_putchar_fd(singled + '0', fd);
		un -= digits * singled;
		digits = digits / 10;
	}
	ft_putchar_fd(un + '0', fd);
}

static unsigned int	ft_ptendigits(unsigned int d)
{
	if (d / 10 == 0)
		return (1);
	return (10 * ft_ptendigits(d / 10));
}
