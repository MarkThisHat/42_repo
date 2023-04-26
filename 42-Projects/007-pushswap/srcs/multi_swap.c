/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:49:12 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/24 19:49:21 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_both(t_ctrl *c)
{
	swap_a(c);
	swap_b(c);
	return(SS);
}

int	rotate_both(t_ctrl *c)
{
	rotate_a(c);
	rotate_b(c);
	return(RR);
}

int	rev_rotate_both(t_ctrl *c)
{
	rev_rotate_a(c);
	rev_rotate_b(c);
	return(RRR);
}
