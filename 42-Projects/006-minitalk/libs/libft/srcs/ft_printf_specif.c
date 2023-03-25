/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specif.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:58:02 by maalexan          #+#    #+#             */
/*   Updated: 2022/12/29 16:58:21 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	s_specif(const char *str, va_list args, int count)
{
	char	c;
	char	*s;

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
	return (i_specif(str, args, count, 0));
}

int	i_specif(const char *str, va_list args, int count, int mode)
{
	int	i;

	if (*str == 'i' || *str == 'd')
	{
		i = va_arg(args, int);
		if (i >= 0 && mode)
		{
			if (mode == 1)
				count += write (1, " ", 1);
			else
				count += write (1, "+", 1);
		}
		count += print_int(i);
		return (print_in(str + 1, args, count));
	}
	return (p_specif(str, args, count));
}

int	p_specif(const char *str, va_list args, int count)
{
	unsigned long	i;

	if (*str == 'p')
	{
		i = va_arg(args, unsigned long);
		if (!i)
			return (print_in(str + 1, args, count += write (1, "(nil)", 5)));
		count += write (1, "0x", 2);
		count += print_base(i, 16, 0);
		return (print_in(str + 1, args, count));
	}
	return (u_specif(str, args, count));
}

int	u_specif(const char *str, va_list args, int count)
{
	int				base;
	int				upp;
	unsigned int	i;

	base = 16;
	if (*str == 'u' || *str == 'x' || *str == 'X')
		i = va_arg(args, unsigned int);
	if (*str == 'u')
		base = 10;
	if (*str == 'X')
		upp = 1;
	else
		upp = 0;
	if (*(str - 1) == '#' && (*str == 'x' || *str == 'X'))
	{
		count += write (1, "0", 1);
		if (i)
			count += write (1, str, 1);
		else
			return (print_in(str + 1, args, count));
	}
	if (*str == 'u' || *str == 'x' || *str == 'X')
		count += print_base(i, base, upp);
	return (print_in(str + 1, args, count));
}
