/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:14:28 by viroques          #+#    #+#             */
/*   Updated: 2019/06/19 20:30:23 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			g_solution;

void	ft_print_screen(int *tab)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = tab[i] + 48;
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int		ft_diago_absolute(int row1, int row2, int col1, int col2)
{
	int diff_row;
	int diff_col;

	diff_row = row1 - row2;
	diff_col = col1 - col2;
	if (diff_row < 0)
		diff_row *= -1;
	if (diff_col < 0)
		diff_col *= -1;
	if (diff_col == diff_row)
		return (1);
	else
		return (0);
}

int		ft_check(int *tab, int col)
{
	int i;

	i = 0;
	while (i < col)
	{
		if (tab[col] == tab[i])
			return (0);
		if (ft_diago_absolute(tab[i], tab[col], i, col) == 1)
			return (0);
		i++;
	}
	return (1);
}

int		ft_solve_queens(int *tab, int col)
{
	int i;

	i = 0;
	if (col == 10)
	{
		g_solution += 1;
		ft_print_screen(tab);
		return (1);
	}
	while (i < 10)
	{
		tab[col] = i;
		if (ft_check(tab, col) == 1)
		{
			ft_solve_queens(tab, col + 1);
		}
		i++;
	}
	return (0);
}

int		ft_ten_queens_puzzle(void)
{
	int tab[10];

	g_solution = 0;
	ft_solve_queens(tab, 0);
	return (g_solution);
}
