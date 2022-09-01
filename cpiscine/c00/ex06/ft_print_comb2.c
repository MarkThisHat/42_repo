/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 08:35:59 by maalexan          #+#    #+#             */
/*   Updated: 2022/07/14 08:47:36 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_print_digits(int n);

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < 100)
	{
		while (j < 100)
		{
			ft_print_digits(i);
			write(1, " ", 1);
			ft_print_digits(j);
			if (i == 98 & j == 99)
				break ;
			j++;
			write(1, ", ", 2);
		}
		i++;
		j = i + 1;
	}
}

void	ft_print_digits(int n)
{
	if (n < 10)
	{
		ft_putchar('0');
		ft_putchar(n + 48);
	}
	else
	{
		ft_putchar((n / 10) + 48);
		ft_putchar((n % 10) + 48);
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
