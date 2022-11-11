/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 09:44:34 by maalexan          #+#    #+#             */
/*   Updated: 2022/07/14 18:15:27 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
int		digit_amount(int n);

void	ft_putnbr(int nb)
{
	int				digits;
	unsigned int	single_char;
	unsigned int	u_nb;

	digits = digit_amount(nb);
	if (nb < 0)
	{
		u_nb = nb * (-1);
		ft_putchar('-');
	}
	else
		u_nb = nb;
	single_char = u_nb;
	while (digits > 1)
	{
		single_char = u_nb / digits;
		ft_putchar(single_char + 48);
		u_nb -= single_char * digits;
		digits = digits / 10;
	}
	ft_putchar(u_nb + 48);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	digit_amount(int n)
{
	if (n / 10 == 0)
		return (1);
	return (10 * digit_amount(n / 10));
}
