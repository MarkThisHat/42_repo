#include "push_swap.h"

static void	full_print(t_ctrl *c)
{
	print_full_stacks(c);
	ft_printf("Push B 6 times:\n");
	push_b(c);
	push_b(c);
	push_b(c);
	push_b(c);
	push_b(c);
	push_b(c);
	print_full_stacks(c);
	ft_printf("Push A 2 times:\n");
	push_a(c);
	push_a(c);
	print_full_stacks(c);
	ft_printf("Swap A\n");
	swap_a(c);
	print_full_stacks(c);
	ft_printf("Swap B\n");
	swap_b(c);
	print_full_stacks(c);
	ft_printf("Swap A and B\n");
	swap_both(c);
	print_full_stacks(c);
	ft_printf("Rotate A (size %i)\n", c->size_a);
	rotate_a(c);
	print_full_stacks(c);
	ft_printf("Rotate B (size %i)\n", c->size_b);
	rotate_b(c);
	print_full_stacks(c);
	ft_printf("Rotate A(%i) and B(%i)\n", c->size_a, c->size_b);
	rotate_both(c);
	print_full_stacks(c);
	ft_printf("Rev rotate A (size %i)\n", c->size_a);
	rev_rotate_a(c);
	print_full_stacks(c);
	ft_printf("Rev rotate B (size %i)\n", c->size_b);
	rev_rotate_b(c);
	print_full_stacks(c);
	ft_printf("Rev rotate A(%i) and B(%i)\n", c->size_a, c->size_b);
	rev_rotate_both(c);
	print_full_stacks(c);
}

static void	partial_print(t_ctrl *c)
{
	print_stacks(c);
	ft_printf("Push B 6 times:\n");
	push_b(c);
	push_b(c);
	push_b(c);
	push_b(c);
	push_b(c);
	push_b(c);
	print_stacks(c);
	ft_printf("Push A 2 times:\n");
	push_a(c);
	push_a(c);
	print_stacks(c);
	ft_printf("Swap A\n");
	swap_a(c);
	print_stacks(c);
	ft_printf("Swap B\n");
	swap_b(c);
	print_stacks(c);
	ft_printf("Swap A and B\n");
	swap_both(c);
	print_stacks(c);
	ft_printf("Rotate A (size %i)\n", c->size_a);
	rotate_a(c);
	print_stacks(c);
	ft_printf("Rotate B (size %i)\n", c->size_b);
	rotate_b(c);
	print_stacks(c);
	ft_printf("Rotate A(%i) and B(%i)\n", c->size_a, c->size_b);
	rotate_both(c);
	print_stacks(c);
	ft_printf("Rev rotate A (size %i)\n", c->size_a);
	rev_rotate_a(c);
	print_stacks(c);
	ft_printf("Rev rotate B (size %i)\n", c->size_b);
	rev_rotate_b(c);
	print_stacks(c);
	ft_printf("Rev rotate A(%i) and B(%i)\n", c->size_a, c->size_b);
	rev_rotate_both(c);
	print_stacks(c);
}

void	test_moves(t_ctrl *c, int mode)
{
	if (mode == 1)
		full_print(c);
	if (mode == 2)
		partial_print(c);
}
