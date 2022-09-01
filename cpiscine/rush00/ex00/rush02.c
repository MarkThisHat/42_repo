/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:09:14 by dapaulin          #+#    #+#             */
/*   Updated: 2022/07/10 14:10:17 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define UP_LEFT 'A'
#define UP_MID	'B'
#define UP_RIGHT 'A'
#define MID_LEFT 'B'
#define MID_MID ' '
#define MID_RIGHT 'B'
#define DOWN_LEFT 'C'
#define DOWN_MID 'B'
#define DOWN_RIGHT 'C'

void	ft_putchar(char c);
void	print_first_line(int n_cols);
void	print_middle_lines(int n_cols, int n_lines);
void	print_last_line(int n_cols, int n_lines);
void	print_line(int n_cols, char frt_char, char mid_char, char lst_char);

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
		return ;
	print_first_line(x);
	print_middle_lines(x, y);
	print_last_line(x, y);
}

// Informs first line print pattern
void	print_first_line(int n_cols)
{
	print_line(n_cols, UP_LEFT, UP_MID, UP_RIGHT);
}

// Informs middle lines print pattern and amounts
void	print_middle_lines(int n_cols, int n_lines)
{
	int	i;

	i = 0;
	while (i < n_lines - 2)
	{
		print_line(n_cols, MID_LEFT, MID_MID, MID_RIGHT);
		i++;
	}
}

// Informs last line print pattern
void	print_last_line(int n_cols, int n_lines)
{
	if (n_lines > 1)
		print_line(n_cols, DOWN_LEFT, DOWN_MID, DOWN_RIGHT);
}

// Handles the actual printing 
void	print_line(int n_cols, char frt_char, char mid_char, char lst_char)
{
	int	i;

	i = 0;
	ft_putchar(frt_char);
	while (i < n_cols - 2)
	{
		ft_putchar(mid_char);
		i++;
	}
	if (n_cols > 1)
		ft_putchar(lst_char);
	ft_putchar('\n');
}
