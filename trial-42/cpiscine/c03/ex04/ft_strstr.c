/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:54:23 by maalexan          #+#    #+#             */
/*   Updated: 2022/07/27 11:50:24 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_compare(char *str, char *to_find, int n);

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	eq_bool;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	eq_bool = 0;
	while (str[i] != '\0' && eq_bool == 0)
	{
		if (str[i] == to_find[0])
			eq_bool = ft_compare(str, to_find, i);
		i++;
	}
	if (eq_bool == 1)
		return (&str[i - 1]);
	else
		return (0);
}

int	ft_compare(char *str, char *to_find, int n)
{
	int	i;

	i = 0;
	while (to_find[i] != '\0')
	{
		if (to_find[i] == str[n])
		{
			i++;
			n++;
		}
		else
			return (0);
	}
	return (1);
}
