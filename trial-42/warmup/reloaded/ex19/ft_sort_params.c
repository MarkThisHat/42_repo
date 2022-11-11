/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:30:33 by coder             #+#    #+#             */
/*   Updated: 2022/09/03 16:30:36 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_arg_sort(char **argv, int argc);
void	ft_ptr_swap(char **ptr1, char **ptr2);
void	ft_put_param(char *argv);
int		ft_strcmp(char *s1, char *s2);

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		return (1);
	ft_arg_sort(argv, argc);
	i = 1;
	while (i < argc)
	{
		ft_put_param(argv[i]);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 == *s2) && (*s1) && (*s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_arg_sort(char **argv, int argc)
{
	int	i;
	int	sorted;

	i = 1;
	sorted = 0;
	while (!sorted)
	{
		i = 1;
		sorted = 1;
		while (i < argc - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				ft_ptr_swap(&argv[i], &argv[i + 1]);
				sorted = 0;
			}
			i++;
		}
	}
}

void	ft_ptr_swap(char **ptr1, char **ptr2)
{
	char	*temp;

	temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

void	ft_put_param(char *argv)
{
	while (*argv)
	{
		ft_putchar(*argv);
		argv++;
	}
	ft_putchar('\n');
}
