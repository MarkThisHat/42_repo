/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:04:48 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/11 10:09:15 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minitalk_bonus.h"

int	get_utf_size(unsigned char c)
{
	if ((c & 0x80) == 0)
		return (1);
	else if ((c & 0xE0) == 0xC0)
		return (2);
	else if ((c & 0xF0) == 0xE0)
		return (3);
	else if ((c & 0xF8) == 0xF0)
		return (4);
	return (0);
}

int	print_utf_eight(char *str)
{
	int	i;
	int	size;
	int len;

	i = 0;
	len = 0;
	while (str[i])
	{
		len++;
		size = get_utf_size(str[i]);
		write(1, &str[i], size);
		i += size;
	}
	return (len);
}

void	leave_program(char *str, int return_code)
{
		if (return_code == 0)
				exit (0);
		ft_putstr_fd(str, 2);
		exit (return_code);
}

void print_binary(char c)
{
	int i;

	for (i = 7; i >= 0; i--) {
		if (c & (1 << i)) {
			ft_printf("1");
		} else {
			ft_printf("0");
		}
	}
	ft_printf("\n");
}


/*
echo -e '\xDF\xB7''\xF0\x9F\x98\x80''\xC3\xB8''\xE1\x8E\x88''\xF0\x9F\x98\x85''\xDF\xA6''\xE1\x8F\xA2''\xF0\x9F\x98\x8A'

int	main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	printf("\nLength is %i\n", print_utf_eight(argv[1]));
	write(1, "\n", 1);
}
*/