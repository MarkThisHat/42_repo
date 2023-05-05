/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:23:27 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/24 20:47:36 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H_BONUS
# define PUSH_SWAP_H_BONUS

# include <unistd.h>
# include "../../libs/libft/incl/libft.h"
# include "../../incl/push_swap.h"

int	is_sorted_bonus(t_ctrl *c);
int	check_duplicates(t_ctrl *c);
int	mover_bonus(t_ctrl *c, char *line);

#endif
