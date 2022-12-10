/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:25:18 by maalexan          #+#    #+#             */
/*   Updated: 2022/12/09 21:00:38 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
	str++;
	if (*str == '%')
	{
		count += write (1, str, 1);
		return (print_in(str + 1, args, count));
	}
	if (*str == '#')
		return (p_flag(str + 1, args, count));
	if (*str == ' ' || *str == '+')
		return (count_signs(str, args, count));
	return (s_flag(str, args, count));
}

int	count_signs(const char *str, va_list args, int count)
{
	int	mode;

	mode = 1;
	while (*str == ' ' || *str == '+')
	{
		if (*str == '+')
			mode = 2;
		str++;
	}
	return (i_flag(str, args, count, mode));
}
