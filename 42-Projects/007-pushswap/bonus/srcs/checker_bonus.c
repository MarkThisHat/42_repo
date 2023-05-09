/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:12:40 by maalexan          #+#    #+#             */
/*   Updated: 2023/05/09 10:27:05 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	fill_stack(t_item *a, int len, char **nbrs, t_item *past)
{
	static int	i;

	i++;
	a->prev = past;
	if (i < len)
	{
		a->n = ft_atoi(nbrs[i]);
		if (i != len - 1)
		{
			a->next = malloc(sizeof(t_item));
			if (!a->next)
				empty_stack(a, 4);
			*a->next = (t_item){0};
			fill_stack(a->next, len, nbrs, a);
		}
	}
}

static t_item	*stack_up(int argc, char **argv)
{
	t_item	*a;

	if (argc == 2)
		exit(0);
	a = malloc(sizeof(t_item) * argc);
	if (!a)
		exit(4);
	*a = (t_item){0};
	fill_stack(a, argc, argv, NULL);
	return (a);
}

static void	publish_result(t_ctrl *c)
{
	if (is_sorted_bonus(c))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

static void	treat_args(t_ctrl *c, int argc, char **argv)
{
	if (argc < 2)
		exit (1);
	check_args(argc, argv);
	c->head_a = stack_up(argc, argv);
	set_control(c, c->head_a, argc - 1);
	check_duplicates(c);
}

int	main(int argc, char **argv)
{
	t_ctrl	c;
	char	*line;
	int		good;
	int		read_flag;

	good = 1;
	read_flag = 1;
	treat_args(&c, argc, argv);
	line = get_next_line(0);
	while (line || read_flag)
	{
		if (good)
			good = mover_bonus(&c, line);
		else
			write (1, "Error\n", 6);
		free(line);
		line = get_next_line(0);
		if (!line)
			read_flag = 0;
	}
	free(line);
	publish_result(&c);
	free_and_leave(&c, 0);
}
