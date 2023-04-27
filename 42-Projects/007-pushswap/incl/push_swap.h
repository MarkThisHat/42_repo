/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:23:27 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/24 20:47:36 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

# include <unistd.h>
# include "../libs/libft/incl/libft.h"

typedef struct s_item	t_item;

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
}	t_ctrl;

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
void	empty_stack(t_item *item);
void	free_and_leave(t_item *stack, int return_code);
void	assess_pile(t_item *head, int size);
void	set_control(t_ctrl *c, t_item *item, int size);
void	switch_adj_nodes(t_item *a, t_item *b);
int		is_sorted(t_ctrl *c);
int		swap_a(t_ctrl *c);
int		swap_b(t_ctrl *c);
int		swap_both(t_ctrl *c);
int		push_a(t_ctrl *c);
int		push_b(t_ctrl *c);
int		rotate_a(t_ctrl *c);
int		rotate_b(t_ctrl *c);
int		rotate_both(t_ctrl *c);
int		rev_rotate_a(t_ctrl *c);
int		rev_rotate_b(t_ctrl *c);
int		rev_rotate_both(t_ctrl *c);
t_item	*sever_node(t_item *item);
t_item	*place_node(t_item *item, t_item *edge);

//not project
void	print_stacks(t_ctrl *c);
void	print_full_stacks(t_ctrl *c);
void	test_moves(t_ctrl *c, int mode);

#endif
