/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:00:16 by maalexan          #+#    #+#             */
/*   Updated: 2022/07/21 10:01:38 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;
	int	validator;

	i = 0;
	validator = 1;
	if (str[i] == '\0')
		return (validator);
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'a' && str[i] <= 'z') \
		&& !(str[i] >= 'A' && str[i] <= 'Z'))
			validator = 0;
		i++;
	}
	return (validator);
}
