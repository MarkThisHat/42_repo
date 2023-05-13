/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:23:27 by maalexan          #+#    #+#             */
/*   Updated: 2023/05/10 19:31:32 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define PB 1
# define PA 2
# define SA 3
# define SB 4
# define RA 5
# define RB 6
# define RRA 7
# define RRB 8
# define SS 9
# define RR 10
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
	t_sol	*next;
};

typedef struct s_ctrl {
	int		size_a;
	int		size_b;
	t_item	*head_a;
	t_item	*head_b;
	t_item	*tail_a;
	t_item	*tail_b;
	t_sol	*answer;
	t_sol	*stream;
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

//		merge_swap.c (4)
void	merge_sort(int *stack, int *invers, int left, int right);
//		ps_utils.c
void	leave_program(char *str, int return_code);
void	empty_stack(t_item *item, int return_code);
void	free_and_leave(t_ctrl *c, int return_code);
void	set_control(t_ctrl *c, t_item *item, int size);
//		push_check.c (4)
int		is_sorted(t_ctrl *c);
void	check_args(int argc, char **argv);
//		node_swap.c
void	free_sol(t_sol *solution);
void	switch_adj_nodes(t_item *a, t_item *b);
void	remove_node(t_sol *head, t_sol *node);
t_item	*sever_node(t_item *item);
t_item	*place_node(t_item *item, t_item *edge);
//		push_index(5)
int		assess_pile(t_item *head, int size);
//		a_moves.c
int		swap_a(t_ctrl *c);
int		rotate_a(t_ctrl *c);
int		rev_rotate_a(t_ctrl *c);
int		push_b(t_ctrl *c);
//		b_moves.c
int		swap_b(t_ctrl *c);
int		rotate_b(t_ctrl *c);
int		rev_rotate_b(t_ctrl *c);
int		push_a(t_ctrl *c);
//		multi_swap.c
int		swap_both(t_ctrl *c);
int		rotate_both(t_ctrl *c);
int		rev_rotate_both(t_ctrl *c);
//		move_swap.c
int		do_move(t_ctrl *c, int move);
int		optimal_partitioning(int size);
int		dive_target(t_item *stack, int target);
int		climb_target(t_item *stack, int target);
int		has_amidst(t_item *stack, int start, int end);
//		print_swap.c (2)
void	print_sol(t_sol *s);
//		solve_swap.c(4)
void	find_sol(t_ctrl *c);
t_sol	*first_move_big(t_ctrl *c, int move);
//		push_sol.c(3)
t_sol	*prep_sol(t_sol *s);
t_sol	*get_stream(t_sol *s);
t_sol	*log_move(int move, t_sol *stack, t_ctrl *c);
//		small_swap.c
void	a_is_three(t_ctrl *c, t_sol *sol);
void	small_sol(t_ctrl *c, int size);
void	sort_three(t_ctrl *c, t_item *head, int is_b);
//		big_swap.c
void	big_sol(t_ctrl *c, int size);
//		opt_swap.c(4)
void	optimize_solution(t_sol *navi, t_sol *head);
//		solc(4)
int		cal_cost(t_item *package, t_item *oppo_head, int *moves);
int		find_cushy_spot(int item, t_item *op);
//		push_reset.c(2)
void	reset_stacks(t_ctrl *c, t_sol *solution);
//		zwap_pivot.c (4)
int		find_pivot(int *arr, int len);

//		TODO
void	set_array(int *sol, int size);
void	solve_small(t_ctrl *c, int *sol);
void	array_sol(t_sol *s, int *sol, t_ctrl *c);
int		find_target(t_item *stack, int target);
t_sol	*prep_sol(t_sol *s);
t_sol	*trace_move(int move, t_sol *stack, t_ctrl *c);
t_sol	*apply_sol(t_sol *s, t_ctrl *c);

//unconsolidated
int		sort_stack(t_ctrl *c, int quadrant, int size);
void	pogo_sol(t_ctrl *c, int size);
void	sol_c(t_ctrl *c, int size);
void	cheap_sol(t_ctrl *c, int size);
//not project
void	print_stacks(t_ctrl *c);
void	print_full_stacks(t_ctrl *c);
void	test_moves(t_ctrl *c, int mode);
void	print_sol_detailed(t_sol *s);

#endif
