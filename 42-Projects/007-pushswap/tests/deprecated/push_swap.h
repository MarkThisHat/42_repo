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

# define PA 1
# define PB 2
# define SA 3
# define SB 4
# define SS 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

# include <unistd.h>
# include "../libs/libft/incl/libft.h"

typedef struct s_item	t_item;
typedef struct s_sol	t_sol;

struct s_item {
	int		n;
	int		i;
	t_item	*next;
	t_item	*prev;
};

struct s_sol {
	int		move;
	int		checkpoint;
	t_sol	*next;
};

typedef struct s_ctrl {
	int		size_a;
	int		size_b;
	t_item	*head_a;
	t_item	*head_b;
	t_item	*tail_a;
	t_item	*tail_b;
	t_sol	*sol_a;
	t_sol	*sol_b;
	t_sol	*a_stream;
	t_sol	*b_stream;
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
void	empty_stack(t_item *item, int return_code);
void	free_and_leave(t_ctrl *c, int return_code);
void	set_control(t_ctrl *c, t_item *item, int size);
void	switch_adj_nodes(t_item *a, t_item *b);
void	print_sol(t_sol *s);
void	set_array(int *sol, int size);
void	solve_small(t_ctrl *c, int *sol);
void	array_sol(t_sol *s, int *sol, t_ctrl *c);
int		find_target(t_item *stack, int target);
int		find_pivot(int *arr, int len);
int		assess_pile(t_item *head, int size);
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
t_sol	*prep_sol(t_sol *s);
t_sol	*trace_move(int move, t_sol *stack, t_ctrl *c);
t_sol	*apply_sol(t_sol *s, t_ctrl *c);
t_item	*sever_node(t_item *item);
t_item	*place_node(t_item *item, t_item *edge);

//unconsolidated
void	find_sol(t_ctrl *c);
int		sort_stack(t_ctrl *c, int quadrant, int size);
//not project
void	print_stacks(t_ctrl *c);
void	print_full_stacks(t_ctrl *c);
void	test_moves(t_ctrl *c, int mode);
void	print_sol_detailed(t_sol *s);

#endif
