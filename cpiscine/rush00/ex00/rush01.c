/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:10:44 by lphelipe          #+#    #+#             */
/*   Updated: 2022/07/10 14:21:08 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define UP_LEFT '/'
#define UP_MID	'*'
#define UP_RIGHT '\\'
#define MID_LEFT '*'
#define MID_MID ' '
#define MID_RIGHT '*'
#define DOWN_LEFT '\\'
#define DOWN_MID '*'
#define DOWN_RIGHT '/'

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
