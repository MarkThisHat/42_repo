#include "push_swap.h"

static void	stack_screen(t_item *a, t_item *b)
{
	if (!a && !b)
		return ;
	if (!a)
		ft_printf("\t\t\t\t\t\t");
	else
	{
		ft_printf("\t*\t%i\t*\t\t\t", a->n);
	}
	if (b)
	{
		ft_printf("*\t%i\t*", b->n);
	}
	ft_printf("\n");
	t_item *a_next = a ? a->next : NULL;
	t_item *b_next = b ? b->next : NULL;
	if (a_next || b_next)
		stack_screen(a_next, b_next);
}

void	print_stacks(t_ctrl *c)
{
	for (int i = 0; i < 69; i++)
		write(1, "-", 1);
	ft_printf("\n\t*    Stack A\t*\t\t\t*    Stack B\t*\n\t*\t\t*\t\t\t*\t\t*\n");
	stack_screen(c->head_a, c->head_b);
	for (int i = 0; i < 69; i++)
		write(1, "-", 1);
	write(1, "\n", 1);
}


static void	stack_full_screen(t_item *a, t_item *b)
{
	if (!a && !b)
		return ;
	if (!a)
		ft_printf("\t\t\t\t\t\t");
	else
	{
		ft_printf("i:%i\t*\t%i\t*\t", a->i, a->n);
		if (a->prev)
			ft_printf("(p-%i)\t", a->prev->n);
		else
			ft_printf(" head\t");
		if (a->next)
			ft_printf("(n-%i)\t", a->next->n);
		else
			ft_printf(" tail\t");
	}
	ft_printf("   \t|   ");
	if (b)
	{
		ft_printf("*\t  %i\t*", b->n);
		if (b->prev)
			ft_printf("\t(p-%i)\t", b->prev->n);
		else
			ft_printf("\thead\t");
		if (b->next)
			ft_printf("(n-%i)\t", b->next->n);
		else
			ft_printf(" tail\t");
		ft_printf("\ti:%i", b->i);
	}
	ft_printf("\n");
	t_item *a_next = a ? a->next : NULL;
	t_item *b_next = b ? b->next : NULL;
	if (a_next || b_next)
		stack_full_screen(a_next, b_next);
}

void	print_full_stacks(t_ctrl *c)
{
	for (int i = 0; i < 111; i++)
		write(1, "-", 1);
	ft_printf("\n\t*    Stack A\t*\t\t\t\t|   *  Stack B\t*\n\t*\t\t*\t\t\t\t|   *\t\t*\n");
	stack_full_screen(c->head_a, c->head_b);
	for (int i = 0; i < 111; i++)
		write(1, "-", 1);
	write(1, "\n", 1);
}

static void	print_move(int move)
{
		if (move == SA)
			write(1, "sa\n", 3);
		else if (move == SB)
			write(1, "sb\n", 3);
		else if (move == SS)
			write(1, "ss\n", 3);
		else if (move == PA)
			write(1, "pa\n", 3);
		else if (move == PB)
			write(1, "pb\n", 3);
		else if (move == RA)
			write(1, "ra\n", 3);
		else if (move == RB)
			write(1, "rb\n", 3);
		else if (move == RR)
			write(1, "rr\n", 3);
		else if (move == RRA)
			write(1, "rra\n", 4);
		else if (move == RRB)
			write(1, "rrb\n", 4);
		else if (move == RRR)
			write(1, "rrr\n", 4);
		else
			ft_printf("oops, move is %i\n", move);
}

void	print_sol_detailed(t_sol *s)
{
	if (!s)
		return ;
//	ft_printf("%i - ", s->checkpoint);
	print_move(s->move);
	print_sol_detailed(s->next);
}

/*
void	switch_nodes(t_item *a, t_item *b)
{
	t_item	*temp_a;
	t_item	*temp_b;

	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	temp_a = a->prev;
	temp_b = b->prev;
	a->prev = a->next;
	b->prev = temp_a;
	a->next = b->next;
	b->next = temp_b;
}
*/

/*presuming this is correct
void	switch_nodes(t_item *a, t_item *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->prev = a->next;
	a->next = b->next;
	b->prev = a->prev;
	b->next = b->prev;
}
*/
/*preindy, gpt says my a->prev is going to be a problem*/




/*
void	switch_nodes(t_item *a, t_item *b)
{
	t_item	*a_prev;
	t_item	*a_next;
	t_item	*b_prev;
	t_item	*b_next;

	a_prev = a->prev;
	a_next = a->next;
	b_prev = b->prev;
	b_next = b->next;
	if (a_prev)
		a_prev->next = b->next;
	if (b_next)
		b_next->prev = b->prev;
	a->prev = b_prev;
	a->next = b_next;
	b->prev = a_prev;
	b->next = a_next;
}

*/
