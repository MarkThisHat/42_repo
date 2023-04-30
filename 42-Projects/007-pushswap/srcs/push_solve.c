#include "push_swap.h"

typedef struct s_sol	t_sol;

struct s_sol {
	int		move;
	int		checkpoint;
	t_sol	*next;
};

int	sort_three(t_item *item, int *sol)
{
	int	a;
	int	b;
	int	c;

	a = item->i;
	b = item->next->i;
	c = item->next->next->i;
	if (a < b && b < c && a < c)
		return (0);
	if (a > b && b < c && a < c)
		*sol = SA;
	if (a > b && b < c && a > c)
		*sol = RA;
	if (*sol)
		return (1);
	if (a > b && b > c)
		*sol = RA;
	if (a < b && b > c)
		*sol = RRA;
	if (a < b && a > c)
		return (1);
	sol++;
	*sol = SA;
	return (2);
}

void	fill_sol(int *sol, int size)
{
	sol[--size] = -1;
	while (size-- + 1)
		sol[size] = 0;
}

t_sol	*apply_sol(t_sol *a, t_ctrl *c)
{
	t_sol	*latest;
	
	while (a)
	{
		if (a->move == SA)
			swap_a(c);
		if (a->move == SB)
			swap_b(c);
		if (a->move == PA)
			push_a(c);
		if (a->move == PB)
			push_b(c);
		if (a->move == RA)
			rotate_a(c);
		if (a->move == RB)
			rotate_b(c);
		if (a->move == RRA)
			rev_rotate_a(c);
		if (a->move == RRB)
			rev_rotate_b(c);
		latest = a;
		a = a->next;
	}
	return (latest);
}

int		weave_sol(t_sol *s, int *sol)
{
	while (*sol > 0)
	{
		s->move = *sol;
		s->next = malloc(sizeof(t_sol));
		if (!s->next)
			return (0);
		*s->next = (t_sol){0};
		s = s->next;
		sol++;
	}
	return (1);
}

void	find_sol(t_ctrl *c)
{
	if (c->size_a != 3)
		return ;
	t_sol	*a;
	t_sol	*b;
	int		sol[3];

	a = malloc(sizeof(t_sol));
	if (!a)
		free_and_leave(c, 4);
	b = NULL;
	(void)b;
	*a = (t_sol){0};
	fill_sol(sol, 3);
	sort_three(c->head_a, sol);
	if (!weave_sol(a, sol))
		free_and_leave(c, 4);
	apply_sol(a, c);
}

/*
int	sort_five(t_ctrl *c, int size)
{
	int	sol[2];
	
	while(size-- > 3)
		push_b(c);
	sol[0] = 0;
	sol[1] = 0;
	sort_three(c->head_a, sol);
	return (0);
}
*/