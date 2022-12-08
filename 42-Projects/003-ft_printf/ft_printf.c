/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:45:27 by maalexan          #+#    #+#             */
/*   Updated: 2022/12/08 18:12:34 by maalexan         ###   ########.fr       */
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
	count = print_input(str, args, 0);
	va_end(args);
	return (count);
}

int	print_input(const char *str, va_list args, int count)
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
		return (print_input(str + 2, args, count + 1));
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
		return (print_input(str + 1, args, count + 1));
	}
	if (*str == 's')
	{
		s = va_arg(args, char *);
		count += print_str(s);
		return (print_input(str + 1, args, count));
	}
	if (*str == 'i' || *str == 'd')
	{
		i = va_arg(args, int);
		count += print_int(i);
		return (print_input(str + 1, args, count));
	}
	return (u_flag(str, args, count));
}

int	u_flag(const char *str, va_list args, int count)
{
	unsigned int	i;
	unsigned long	u;

	if (*str == 'u')
	{
		i = va_arg(args, unsigned int);
		count += print_base(i, 10, 0);
	}
	if (*str == 'p')
	{
		u = va_arg(args, unsigned long);
		write (1, "0x", 2);
		count += print_base(u, 16, 0) + 2;
	}
	if (*str == 'x')
	{
		i = va_arg(args, unsigned int);
		count += print_base(i, 16, 0);
	}
	if (*str == 'X')
	{
		i = va_arg(args, unsigned int);
		count += print_base(i, 16, 1);
	}
	return (print_input(str + 1, args, count));
}
