#include "push_swap_bonus.h"

int		mover_bonus(t_ctrl *c, char *line)
{
	if (!ft_strncmp("sa\n", line, 3))
		swap_a(c);
	else if (!ft_strncmp("sb\n", line, 3))
		swap_b(c);
	else if (!ft_strncmp("ss\n", line, 3))
		swap_both(c);
	else if (!ft_strncmp("pa\n", line, 3))
		push_a(c);
	else if (!ft_strncmp("pb\n", line, 3))
		push_b(c);
	else if (!ft_strncmp("ra\n", line, 3))
		rotate_a(c);
	else if (!ft_strncmp("rb\n", line, 3))
		rotate_b(c);
	else if (!ft_strncmp("rr\n", line, 3))
		rotate_both(c);
	else if (!ft_strncmp("rra\n", line, 4))
		rev_rotate_a(c);
	else if (!ft_strncmp("rrb\n", line, 4))
		rev_rotate_b(c);
	else if (!ft_strncmp("rrr\n", line, 4))
		rev_rotate_both(c);
	else
		return (0);
	return (1);
}