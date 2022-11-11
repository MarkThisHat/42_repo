/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 21:57:22 by coder             #+#    #+#             */
/*   Updated: 2022/08/27 21:57:24 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_put_param(char *argv);

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		return (1);
	i = 1;
	while (i < argc)
	{
		ft_put_param(argv[i]);
		i++;
	}
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
