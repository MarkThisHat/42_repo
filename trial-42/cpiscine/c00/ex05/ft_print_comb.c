/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:23:22 by maalexan          #+#    #+#             */
/*   Updated: 2022/07/13 19:02:40 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_print_digits(int h, int d, int u);

void	ft_print_comb(void)
{
	int	h;
	int	d;
	int	u;

	h = 0;
	d = 0;
	u = 0;
	while (h < 8)
	{
		ft_print_digits(h, d, u);
		while (d < 9)
		{
			ft_print_digits(h, d, u);
			while (u < 10)
			{
				ft_print_digits(h, d, u);
				u++;
			}
			u = 0;
			d++;
		}
		d = 0;
		h++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_digits(int h, int d, int u)
{
	if (h != d && d != u && d != u && h < d && d < u)
	{
		ft_putchar(h + 48);
		ft_putchar(d + 48);
		ft_putchar(u + 48);
		if (h != 7)
			write(1, ", ", 2);
	}
}
