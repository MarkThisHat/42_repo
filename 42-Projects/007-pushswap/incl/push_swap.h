/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:23:27 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/24 19:22:51 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../libs/libft/incl/libft.h"

typedef struct s_item t_item;

struct s_item {
	int		n;
	int		i;
	t_item	*next;
	t_item	*prev;
};

typedef struct s_ctrl {
	int		size_a;
	int		size_b;
	t_item	*head_a;
	t_item	*head_b;
	t_item	*tail_a;
	t_item	*tail_b;
} t_ctrl;

typedef struct s_merge_data
{
	int	left;
	int	middle;
	int	right;
	int	*stack;
	int	*invers;
	int	*l_half;
	int	*r_half;
}				t_merge_data;

void	merge_sort(int *stack, int *invers, int left, int right);
void	leave_program(char *str, int return_code);
void	check_args(int argc, char **argv);
int		check_unique(int *stack, t_item *item, int size, int *invers);
void	empty_stack(t_item *item);
void	free_and_leave(t_item *stack, int return_code);
int		assess_pile(t_item *head, int size);

#endif
