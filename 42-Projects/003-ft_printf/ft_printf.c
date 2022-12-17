/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:45:27 by maalexan          #+#    #+#             */
/*   Updated: 2022/12/09 19:23:14 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	if (!str)
		return (-1);
	va_start(args, str);
	count = print_in(str, args, 0);
	va_end(args);
	return (count);
}

int	print_in(const char *str, va_list args, int count)
{
	while (*str != '%' && *str)
	{
		write(1, str, 1);
		count++;
		str++;
	}
	if (!*str)
		return (count);
	if (*(str + 1) == '%')
	{
		write (1, str, 1);
		return (print_in(str + 2, args, count + 1));
	}
	return (s_flag(str + 1, args, count));
}

int	s_flag(const char *str, va_list args, int count)
{
	char	c;
	char	*s;
	int		i;

	if (*str == 'c')
	{
		c = va_arg(args, int);
		write(1, &c, 1);
		return (print_in(str + 1, args, count + 1));
	}
	if (*str == 's')
	{
		s = va_arg(args, char *);
		if (!s)
			return (print_in(str + 1, args, count += write (1, "(null)", 6)));
		count += print_str(s);
		return (print_in(str + 1, args, count));
	}
	if (*str == 'i' || *str == 'd')
	{
		i = va_arg(args, int);
		count += print_int(i);
		return (print_in(str + 1, args, count));
	}
	return (u_flag(str, args, count));
}

int	u_flag(const char *str, va_list args, int count)
{
	int				base;
	int				upp;
	unsigned long	i;

	base = 16;
	if (*str == 'u' || *str == 'x' || *str == 'X')
		i = va_arg(args, unsigned int);
	if (*str == 'p')
	{
		i = va_arg(args, unsigned long);
		if (!i)
			return (print_in(str + 1, args, count += write (1, "(nil)", 5)));
		count += write (1, "0x", 2);
	}
	if (*str == 'u')
		base = 10;
	if (*str == 'X')
		upp = 1;
	else
		upp = 0;
	if (*str == 'p' || *str == 'u' || *str == 'x' || *str == 'X')
		count += print_base(i, base, upp);
	return (print_in(str + 1, args, count));
}
