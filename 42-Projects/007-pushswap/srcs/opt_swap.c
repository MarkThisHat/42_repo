#include "push_swap.h"

static int is_redundant(int move1, int move2)
{
	if (move1 == RA && move2 == RRA)
		return (1);
	if (move1 == RRA && move2 == RA)
		return (1);
	if (move1 == RB && move2 == RRB)
		return (1);
	if (move1 == RRB && move2 == RB)
		return (1);
	if (move1 == PA && move2 == PB)
		return (1);
	if (move1 == PB && move2 == PA)
		return (1);
	if (move1 == SA && move2 == SA)
		return (1);
	if (move1 == SB && move2 == SB)
		return (1);
	return (0);
}

static	int	change_move(int move, int upgrade)
{
	if (upgrade && move == SA)
		return (SS);
	if (upgrade && move == SB)
		return (SS);
	if (upgrade && move == RA)
		return (RR);
	if (upgrade && move == RB)
		return (RR);
	if (upgrade && move == RRA)
		return (RRR);
	if (upgrade && move == RRB)
		return (RRR);
	if (!upgrade && move == SA)
		return (SB);
	if (!upgrade && move == SB)
		return (SA);
	if (!upgrade && move == RA)
		return (RB);
	if (!upgrade && move == RB)
		return (RA);
	if (!upgrade && move == RRA)
		return (RRB);
	if (!upgrade && move == RRB)
		return (RRA);
	return (0);
}

static t_sol	*find_replacement(t_sol *navi, int move)
{
	if (!move)
		return (NULL);
	while (navi && navi->move >= PA)
	{
		if (navi->move == move)
			return (navi);
		else
			navi = navi->next;
	}
	return (NULL);
}

static int wipe_unecessary(t_sol *navi, t_sol *head, int optimized)
{
	t_sol *temp;
	t_sol *prev;

	temp = NULL;
	prev = NULL;
	while (navi)
	{
		if (navi->next && is_redundant(navi->move, navi->next->move))
		{
			temp = navi->next->next;
			remove_node(head, navi->next);
			remove_node(head, navi);
			if (prev)
				prev->next = temp;
			navi = temp;
			optimized = 0;
		}
		else
		{
			prev = navi;
			navi = navi->next;
		}
	}
	return (optimized);
}

void optimize_solution(t_sol *navi, t_sol *head)
{
	t_sol	*temp;
	int		opt;

	opt = 0;
	while (!opt)
		opt = wipe_unecessary(navi, head, 1);
	while (navi && navi->move <= PA)
		navi = navi->next;
	if (!navi)
		return;
	temp = NULL;
	if (navi->move >= SA && navi->move <= RRB)
	{
		temp = find_replacement(navi, change_move(navi->move, 0));
		if (temp)
		{
			navi->move = change_move(navi->move, 1);
			remove_node(head, temp);
		}
	}
	optimize_solution(navi->next, head);
}

/*
static	int	compli_move(int move)
{
	if (move == SA)
		return (SB);
	if (move == SB)
		return (SA);
	if (move == RA)
		return (RB);
	if (move == RB)
		return (RA);
	if (move == RRA)
		return (RRB);
	if (move == RRB)
		return (RRA);
	return (0);
}

static	int	upgrade_move(int move)
{
	if (move == SA)
		return (SS);
	if (move == SB)
		return (SS);
	if (move == RA)
		return (RR);
	if (move == RB)
		return (RR);
	if (move == RRA)
		return (RRR);
	if (move == RRB)
		return (RRR);
	return (0);
}*/