/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:27:35 by maalexan          #+#    #+#             */
/*   Updated: 2023/01/26 17:08:39 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_whitespace(const char c)
{
	if (c == ' ' || c == '\f' || c == '\n' \
	|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ref_base(int c, int base)
{
	char	strl[17];
	char	stru[17];
	int		i;

	i = 0;
	ft_strlcpy(strl, "0123456789abcdef", 17);
	ft_strlcpy(stru, "0123456789ABCDEF", 17);
	while (i < base)
	{
		if (c == strl[i] || c == stru[i])
			return (i);
		i++;
	}
	return (-1);
}

int	hexnotation(const char *str, int i)
{
	if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
		i += 2;
	return (i);
}

int	ft_atoi_base(const char *str, int base)
{
	int	nb;
	int	sign;
	int	i;

	nb = 0;
	sign = 1;
	i = 0;
	while (ft_whitespace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	i = hexnotation(str, i);
	while (ref_base(str[i], base) != -1)
	{
		nb = nb * base;
		nb = nb + ref_base(str[i], base);
		i++;
	}
	return (nb * sign);
}
