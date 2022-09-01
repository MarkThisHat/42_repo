/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:20:29 by maalexan          #+#    #+#             */
/*   Updated: 2022/07/25 09:20:49 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;
	int	validator;

	i = 0;
	validator = 1;
	if (str[i] == '\0')
		return (validator);
	while (str[i] != '\0')
	{
		if ((str[i] < 32) || (str[i] == 127))
			validator = 0;
		i++;
	}
	return (validator);
}
