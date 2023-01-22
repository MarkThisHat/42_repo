/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:39:59 by maalexan          #+#    #+#             */
/*   Updated: 2023/01/22 12:41:51 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/incl/libft.h"

int	validate_usage(int	argc, char **argv);
void	leave_program(char *str, int fd, int return_code);