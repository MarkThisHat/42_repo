/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:53:30 by maalexan          #+#    #+#             */
/*   Updated: 2022/07/25 09:53:57 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	is_word;

	i = 0;
	is_word = 0;
	while (str[i] != '\0')
	{
		if (((str[i] >= 'A' && str[i] <= 'Z') || \
		(str[i] >= '0' && str[i] <= '9')) && (is_word == 0))
			is_word = 1;
		else if ((str[i] >= 'a' && str[i] <= 'z') && (is_word == 0))
		{
			if (!(str[i - 1] >= '0' && str[i - 1] <= '9'))
				str[i] -= 32;
			is_word = 1;
		}
		else if (!(str[i] >= 'a' && str[i] <= 'z') \
		&& !(str[i] >= '0' && str[i] <= '9') \
		&& !(str[i] >= 'A' && str[i] <= 'Z') && (is_word == 1))
			is_word = 0;
		else if ((str[i] >= 'A' && str[i] <= 'Z') && (is_word == 1))
			str[i] += 32;
		i++;
	}
	return (str);
}
