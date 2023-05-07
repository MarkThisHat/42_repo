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

void optimize_solution(t_sol *navi, t_sol *head)
{
	t_sol *temp;

	temp = NULL;
	while (navi && navi->move <= PA)
		navi = navi->next;
	if (!navi)
		return;
	if (navi->next && is_redundant(navi->move, navi->next->move))
	{
		temp = navi->next;
		remove_node(head, navi);
		remove_node(head, temp);
	}
	else if (navi->move >= SA && navi->move <= RRB)
	{
		temp = find_replacement(navi, compli_move(navi->move));
		if (temp)
		{
			navi->move = upgrade_move(navi->move);
			remove_node(head, temp);
		}
	}
	optimize_solution(navi->next, head);
}
