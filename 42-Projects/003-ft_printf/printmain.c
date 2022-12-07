/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:25:19 by maalexan          #+#    #+#             */
/*   Updated: 2022/12/07 15:42:57 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	ft_printf(const char *str, ...);

int	main(void)
{
	char	c;
	int		original;
	int		farseta;

	c = 'z';
	printf("Ft:\n");
	farseta = ft_printf("Percent here: %%, Character c is %c\n", c);
	printf("Ori:\n");
	original = printf("Percent here: %%, Character c is %c\n", c);
	printf("ft: %i std: %i\n", farseta, original);
}

