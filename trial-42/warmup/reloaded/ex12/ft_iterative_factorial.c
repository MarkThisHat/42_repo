/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 20:09:11 by coder             #+#    #+#             */
/*   Updated: 2022/09/03 20:26:44 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;

	if (nb < 0 || nb > 12)
		return (0);
	if (nb < 2)
		return (1);
	i = nb;
	while (i > 1)
	{
		nb *= (i - 1);
		i--;
	}
	return (nb);
}
