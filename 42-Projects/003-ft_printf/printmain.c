/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:25:19 by maalexan          #+#    #+#             */
/*   Updated: 2022/12/07 21:58:50 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	ft_printf(const char *str, ...);

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
}
