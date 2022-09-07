/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:22:46 by maalexan          #+#    #+#             */
/*   Updated: 2022/09/07 16:22:46 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			r = i;
		i++;
	}
	if (r != 0)
		return ((char *)&str[r]);
	return (0);
}
