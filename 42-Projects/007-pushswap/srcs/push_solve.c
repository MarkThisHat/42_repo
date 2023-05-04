#include "push_swap.h"

int	find_target(t_item *stack, int target)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->i == target)
			return (position);
		stack = stack->next;
		position++;
	}
	return (-1);
}

void	set_checkpoint(t_sol **s, int step)
{
	(*s)->checkpoint = step;
	(*s) = (*s)->next;
}

void	found_checkpoint(t_sol **a, t_sol **b, int *step)
{
	if ((*a)->move == PB)
	{
		while ((*a) && (*a)->move == PB)
			set_checkpoint(a, *step);
		*step += 1;
		while ((*b) && (*b)->move != PA)
			set_checkpoint(b, *step);
	}
	else if ((*b)->move == PA)
	{
		while ((*a) && (*a)->move != PB)
			set_checkpoint(a, *step);
		*step += 1;
		while ((*b) && (*b)->move == PA)
			set_checkpoint(b, *step);
	}
}

void	checkpoint_sol(t_ctrl *c)
{
	t_sol	*nav_a;
	t_sol	*nav_b;
	int		step;

	step = 0;
	nav_a = c->sol_a;
	nav_b = c->sol_b;
	while (nav_a && nav_b)
	{
		if (nav_a->move == PB || nav_b->move == PA)
			found_checkpoint(&nav_a, &nav_b, &step);
		else
		{
			set_checkpoint(&nav_a, step);
			set_checkpoint(&nav_b, step);
		}
	}
	step++;
	while (nav_a)
		set_checkpoint(&nav_a, step);
	while (nav_b)
		set_checkpoint(&nav_b, step);
}

t_sol *stitch_sol(t_sol *a, t_sol *b)
{
	t_sol *merged = NULL;
	t_sol **current = &merged;

	while (a && b)
	{
		if (a->checkpoint <= b->checkpoint)
		{
			*current = a;
			a = a->next;
		}
		else
		{
			*current = b;
			b = b->next;
		}
		current = &((*current)->next);
	}
	if (a != NULL)
		*current = a;
	else
		*current = b;
	return (merged);
}

t_sol	*return_used(t_ctrl *c)
{
	if (c->sol_a)
		return (c->sol_a);
	else if (c->sol_b)
		return (c->sol_b);
	else
		return (NULL);
}

t_sol	*nullify_unused(t_ctrl *c)
{
	t_sol	*temp;
	int		a;
	int		b;

	a = 0;
	b = 0;
	temp = c->sol_a;
	while (temp)
	{
		temp = temp->next;
		a++;
	}
	temp = c->sol_b;
	{
		temp = temp->next;
		b++;
	}
	if (a < b)
		c->sol_a = NULL;
	else
		c->sol_b = NULL;
	return (return_used(c));
}
/*
t_sol*	seek_move(int)

void	optimize_sol(t_sol	*s)
{
	t_sol	*current;
	int		checkpoint;

	current = s;
	checkpoint = s->checkpoint;

}
*/
void	find_sol(t_ctrl *c)
{
	int		sol[3];

	c->sol_a = prep_sol(c->sol_a);
	c->sol_b = prep_sol(c->sol_b);
	if (!c->sol_a || !c->sol_b)
		free_and_leave(c, 4);
	c->a_stream = c->sol_a;
	c->b_stream = c->sol_b;
	if (c->size_a < 7)
		solve_small(c, sol);
	if (c->size_a < 4)
		return ;
	ft_printf("\nPre checkpoint sol:\n");
	print_sol_detailed(c->sol_a);
	print_sol_detailed(c->sol_b);
	checkpoint_sol(c);
	ft_printf("\nPre stitch sol:\n");
	print_sol_detailed(c->sol_a);
	print_sol_detailed(c->sol_b);
	stitch_sol(c->sol_a, c->sol_b);
	c->sol_a = nullify_unused(c);
	ft_printf("\nLast Print:\n");
	print_sol_detailed(c->sol_a);

}




/* 6 1 4 3 2 5 (optimizeable)
t_sol *stitch_sol(t_sol *a, t_sol *b)
{
	t_sol *merged = NULL;
	t_sol **current = &merged;

	while (a != NULL && b != NULL)
	{
		if (a->checkpoint == b->checkpoint)
		{
			*current = a;
			a = a->next;
			current = &((*current)->next);
			*current = b;
			b = b->next;
			current = &((*current)->next);
		}
		else if (a->checkpoint < b->checkpoint)
		{
			*current = a;
			a = a->next;
			current = &((*current)->next);
		}
		else
		{
			*current = b;
			b = b->next;
			current = &((*current)->next);
		}
	}
	if (a != NULL)
		*current = a;
	else
		*current = b;
	return (merged);
}


t_sol	*stitch_sol(t_sol *a, t_sol *b)
{
	t_sol	*stitcher;
	int		checkpoint;

	stitcher = a;
	checkpoint = stitcher->checkpoint;
	while (stitcher)
	{

	}
	return (a);
}
gpt sugg
t_sol *stitch_sol(t_sol *a, t_sol *b)
{
    t_sol *merged = NULL;
    t_sol **current = &merged;

    while (a != NULL && b != NULL)
    {
        if (a->checkpoint == b->checkpoint)
        {
            *current = a;
            a = a->next;
            current = &((*current)->next);
            *current = b;
            b = b->next;
            current = &((*current)->next);
        }
        else if (a->checkpoint < b->checkpoint)
        {
            *current = a;
            a = a->next;
            current = &((*current)->next);
        }
        else
        {
            *current = b;
            b = b->next;
            current = &((*current)->next);
        }
    }

    // Append the remaining nodes from the non-empty list
    if (a != NULL)
        *current = a;
    else
        *current = b;

    return merged;
}

*/