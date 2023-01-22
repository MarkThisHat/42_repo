/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:37:28 by maalexan          #+#    #+#             */
/*   Updated: 2023/01/22 13:32:14 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

int	main(int argc, char **argv)
{
	if (validate_usage(argc, argv))
		leave_program(0, 0, 0);
}

int	validate_usage(int	argc, char **argv)
{
	int	len;

	if (argc != 2)
		leave_program("Usage: <program name> <file.fdf>\n", 2, 1);
	len = ft_strlen(argv[1]);
	if (len < 5 || ft_strncmp(".fdf", &argv[1][len -4], 5))
		leave_program("Please input a valid <.fdf> file\n", 2, 1);
	return (1);
}

void	leave_program(char *str, int fd, int return_code)
{
	if (return_code == 0)
		exit (0);
	ft_putstr_fd(str, fd);
	exit (return_code);
}
