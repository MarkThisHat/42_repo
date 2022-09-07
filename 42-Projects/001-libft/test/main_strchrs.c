/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strchrs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:33:44 by maalexan          #+#    #+#             */
/*   Updated: 2022/09/07 16:33:44 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strchr(char *str, int c);
char	*ft_strrchr(char *str, int c);

int	main(void)
{
	char	str[] = "Batata";

	printf("Strchr:\n%s\n", ft_strchr(str, 't'));
	printf("Strrchr:\n%s\n", ft_strrchr(str, 't'));
}
