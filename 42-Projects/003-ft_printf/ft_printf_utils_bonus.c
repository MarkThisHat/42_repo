/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:05:42 by maalexan          #+#    #+#             */
/*   Updated: 2022/12/09 19:57:00 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_base(unsigned long n, int base, int upp)
{
	char	number[21];
	char	*ptr;
	int		ascii;

	ptr = number + 20;
	*ptr = '\0';
	ascii = 87;
	if (upp)
		ascii -= 32;
	while (42)
	{
		if (10 > (n % base))
			*--ptr = '0' + (n % base);
		else
			*--ptr = ascii + (n % base);
		n /= base;
		if (!n)
			break ;
	}
	return (print_str(ptr));
}

int	print_int(int n)
{
	char	number[12];
	char	*ptr;
	int		negative;

	ptr = number + 11;
	*ptr = '\0';
	negative = (n < 0);
	while (42)
	{
		if (n > 0)
			*--ptr = '0' + (n % 10);
		else
			*--ptr = '0' - (n % 10);
		n /= 10;
		if (!n)
			break ;
	}
	if (negative)
		*--ptr = '-';
	return (print_str(ptr));
}

int	print_str(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
