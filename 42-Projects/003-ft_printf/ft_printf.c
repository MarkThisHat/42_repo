/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:45:27 by maalexan          #+#    #+#             */
/*   Updated: 2022/12/06 18:31:00 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "libft.h"*/
#include <stdarg.h>
#include <unistd.h>
int	print_input(const char *str, va_list args, int count);
int	flag_treat(const char *str, va_list args, int count);

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	if (!str)
		return (-1);
	va_start(args, str);
	count = print_input(str, args, 0);
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
	if (!str)
	{
		va_end(args);
		return (count);
	}
	if (*(str + 1) == '%')
	{
		write (1, str, 1);
		return (print_input(str + 2, args, count + 1));
	}
	return (flag_treat(str, args, count));
}

int	flag_treat(const char *str, va_list args, int count)
{
	char	c;
/*	int		i;
	char	*s;*/

	if (*str == 'c')
	{
		c = va_arg(args, int);
		write(1, &c, 1);
		return (print_input(str + 1, args, count + 1));
	}
	write(1, "!!!Flag Not Supported!!!", 25);
	count++;
	return (print_input(str + 1, args, count));
}
