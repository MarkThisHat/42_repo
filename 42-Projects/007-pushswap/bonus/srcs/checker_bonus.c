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

int	main(int argc, char **argv)
{
	t_ctrl	c;
	char	*line;
	int		fd;
	int		good;

	fd = 0;
	good = 1;
	if (argc < 2)
		return (1);
	check_args(argc, argv);
	c.head_a = stack_up(argc, argv);
	set_control(&c, c.head_a, argc - 1);
	check_duplicates(&c);
	while ((line = get_next_line(fd)))
	{
		if (good)
			good = mover_bonus(&c, line);
		else
			write (1, "Error\n", 6);
		free(line);
//		print_stacks(&c);
	}
	free(line);
//	print_stacks(&c);
	if (is_sorted_bonus(&c))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_and_leave(&c, 0);
}