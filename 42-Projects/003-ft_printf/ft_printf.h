/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:06:57 by maalexan          #+#    #+#             */
/*   Updated: 2022/12/08 18:13:53 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	print_input(const char *str, va_list args, int count);
int	s_flag(const char *str, va_list args, int count);
int	u_flag(const char *str, va_list args, int count);
int	print_base(unsigned long n, int base, int upp);
int	print_str(char	*str);
int	print_int(int n);

#endif