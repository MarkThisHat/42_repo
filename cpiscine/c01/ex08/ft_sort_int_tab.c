/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:51:58 by maalexan          #+#    #+#             */
/*   Updated: 2022/07/19 15:58:46 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b);

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	sorted;

	sorted = 0;
	while (1)
	{	
		if (sorted == 0)
		{
			i = 0;
			sorted = 1;
			while (i < size - 1)
			{
				if (tab[i] > tab[i + 1])
				{
					ft_swap(&tab[i], &tab[i + 1]);
					sorted = 0;
				}
				i++;
			}
		}
		else
			return ;
	}
}

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}
