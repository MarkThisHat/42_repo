/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:23:27 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/19 11:16:53 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../libs/libft/incl/libft.h"

typedef struct s_pile t_pile;

struct s_pile {
	int		n;
	int		i;
	t_pile	*next;
	t_pile	*prev;
	t_pile	*head;
	t_pile	*tail;
};

void	leave_program(char *str, int return_code);
void	check_args(int argc, char **argv);
void	check_digits(char *str);
void	check_size(char *str);

#endif
