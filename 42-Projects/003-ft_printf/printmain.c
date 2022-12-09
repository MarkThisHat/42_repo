/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:25:19 by maalexan          #+#    #+#             */
/*   Updated: 2022/12/09 11:38:59 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	char	c;
	char	*s = "hello";
	int		i;
	int		original;
	int		farseta;
	unsigned int	u;
	char	*nulo;

	nulo = NULL;
	c = 'z';
	i = 2147483647;
	u = 3849023849;
	printf("Ft:\n");
	farseta = ft_printf("Percent here: %%, Character c is %c\nString is %s\nInteger i is %i and d %d\nand unsigned %u\nand smolhex %x\nand bighex %X\nand ptr %p\n", c, s, i, i, u, u, u, s);
	printf("Ori:\n");
	original = printf("Percent here: %%, Character c is %c\nString is %s\nInteger i is %i and d %d\nand unsigned %u\nand smolhex %x\nand bighex %X\nand ptr %p\n", c, s, i, i, u, u, u, s);
	printf("ft: %i std: %i\n", farseta, original);
	ft_printf("nuloboy %s\n", nulo);
}


/*
int	main(void)
{
	char	c;
	char	*s = "hello";
	int		i;
	unsigned int u;
	int		original;
	int		farseta;

	c = 'z';
	i = 2147483647;
	u = 4012385987;
	printf("Ft:\n");
	farseta = ft_printf("Percent here: %%, Character c is %c\nString is %s\nInteger i is %i and d %d\nUnsigned is %u\nPepe\n%%\n", c, s, i, i, u);
	printf("Ori:\n");
	original = printf("Percent here: %%, Character c is %c\nString is %s\nInteger i is %i and d %d\nUnsigned is %u\nPepe\n%%\n", c, s, i, i, u);
	printf("ft: %i std: %i\n", farseta, original);
}*/
