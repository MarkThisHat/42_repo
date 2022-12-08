/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:45:27 by maalexan          #+#    #+#             */
/*   Updated: 2022/12/08 17:41:11 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	print_input(const char *str, va_list args, int count);
int simple_flag(const char *str, va_list args, int count);
int complex_flag(const char *str, va_list args, int count);
int	print_base(unsigned long n, int base, int upp);
int	print_str(char	*str);
int	print_int(int n);

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
	return (simple_flag(str + 1, args, count));
}

int	simple_flag(const char *str, va_list args, int count)
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
	return (complex_flag(str, args, count));
}

int	complex_flag(const char *str, va_list args, int count)
{
	unsigned int	i;
	unsigned long	u;
	
	if (*str == 'u')
	{
		i = va_arg(args, unsigned int);
		count += print_base(i, 10, 0);
		return (print_input(str + 1, args, count));
	}
	if (*str == 'p')
	{
		u = va_arg(args, unsigned long);
		write (1, "0x", 2);
		count += print_base(u, 16, 0);
		return (print_input(str + 1, args, count + 2));
	}
	if (*str == 'x')
	{
		i = va_arg(args, unsigned int);
		count += print_base(i, 16, 0);
		return (print_input(str + 1, args, count));
	}
	if (*str == 'X')
	{
		i = va_arg(args, unsigned int);
		count += print_base(i, 16, 1);
		return (print_input(str + 1, args, count));
	}
	return (print_input(str + 1, args, count));
}

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
