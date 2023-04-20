/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:42:08 by maalexan          #+#    #+#             */
/*   Updated: 2023/04/19 11:17:22 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_pile(t_pile *pile)
{
	while (pile->next)
	{
		ft_printf("%i", pile->n);
		print_pile(pile->next);
	}
}

void	fill_a(t_pile *a, int len, char **nbrs)
{
	static int	i;

	i++;
	while (i < len)
	{
		a->next = malloc(sizeof(t_pile));
		if (!a->next)
			ft_printf("bummer on i %i\n", i);
		a->n = ft_atoi(nbrs[i]);
		fill_a(a->next, len, nbrs);
	}
	a->next = NULL;
}

t_pile	*stack_up(int argc, char **argv)
{
	t_pile *a;

	if (argc == 2)
		exit(0);
	a = malloc(sizeof(t_pile) * argc);
	if (!a)
		exit(4);
	a->prev = NULL;
	fill_a(a, argc, argv);
	return (a);
}

int	main(int argc, char **argv)
{
	t_pile	*a;
	t_pile	*b;

	if (argc < 2)
		return (1);
	a = stack_up(argc, argv);
	check_args(argc, argv);
	ft_printf("nice args!\n");
	print_pile(a);
	(void)b;
}