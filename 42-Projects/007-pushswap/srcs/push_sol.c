/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:05:09 by maalexan          #+#    #+#             */
/*   Updated: 2023/05/08 17:10:24 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_sol	*prep_sol(t_sol *s)
{
	s = malloc(sizeof(t_sol));
	if (!s)
		return (NULL);
	*s = (t_sol){0};
	return (s);
}

t_sol	*log_move(int move, t_sol *stack, t_ctrl *c)
{
	stack->next = prep_sol(stack->next);
	if (!stack->next)
		free_and_leave(c, 4);
	stack->next->move = move;
	return (stack->next);
}

t_sol	*get_stream(t_sol *s)
{
	if (s->next)
		return (get_stream(s->next));
	return (s);
}

t_sol	*first_move_big(t_ctrl *c, int move)
{
	t_sol	*list;

	list = malloc(sizeof(t_sol));
	if (!list)
		free_and_leave(c, 4);
	*list = (t_sol){0};
	list->move = do_move(c, move);
	return (list);
}
