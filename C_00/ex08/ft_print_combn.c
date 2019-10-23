/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:22:29 by viroques          #+#    #+#             */
/*   Updated: 2019/06/19 13:57:51 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_display(int *tab, int size)
{
	int i;
	int check;

	i = 0;
	check = 1;
	while (i < size - 1)
	{
		if (tab[i] >= tab[i + 1])
			check = 0;
		i++;
	}
	if (check == 1)
	{
		i = 0;
		while (i < size)
			ft_putchar(tab[i++] + '0');
		if (tab[0] < (10 - size))
			write(1, ", ", 2);
	}
}

void	ft_display_one(void)
{
	int i;

	i = 0;
	while (i < 10)
	{
		ft_putchar(i + '0');
		if (i != 9)
			write(1, ", ", 2);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	tab[10];
	int i;

	i = 0;
	if (n == 1)
		ft_display_one();
	while (i < n && n < 10)
		tab[i++] = 0;
	while (tab[0] <= (10 - n) && n > 1 && n < 10)
	{
		ft_display(tab, n);
		tab[n - 1]++;
		i = n;
		while (i && n > 1)
		{
			i--;
			if (tab[i] > 9)
			{
				tab[i - 1]++;
				tab[i] = 0;
			}
		}
	}
}
