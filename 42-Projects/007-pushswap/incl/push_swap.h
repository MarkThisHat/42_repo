/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:23:27 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/18 20:46:28 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../libs/libft/incl/libft.h"

typedef struct s_pile t_pile;

typedef struct s_gob {
	t_pile	*head;
	t_pile	*tail;
}	t_gob;

struct s_pile {
	t_gob	*edge;
	int		n;
	int		i;
	t_pile	*next;
	t_pile	*prev;
};

void	leave_program(char *str, int return_code);
void	check_args(int argc, char **argv);
void	check_digits(char *str);
void	check_size(char *str);

#endif
