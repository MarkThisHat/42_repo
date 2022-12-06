/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:25:19 by maalexan          #+#    #+#             */
/*   Updated: 2022/12/06 22:40:24 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	ft_printf(const char *str, ...);

int	main(void)
{
	char	c;

	c = 'z';
	printf("Man:\n");
	ft_printf("Character c is %c\n", c);
	printf("Ft:\n");
	printf("Character c is %c\n", c);
}

