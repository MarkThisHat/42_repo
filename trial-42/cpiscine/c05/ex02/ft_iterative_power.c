/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:52:27 by maalexan          #+#    #+#             */
/*   Updated: 2022/07/28 17:13:25 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	n;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	i = 1;
	n = nb;
	while (i < power)
	{
		nb *= n;
		i++;
	}
	return (nb);
}
