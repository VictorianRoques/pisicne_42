/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 11:35:42 by viroques          #+#    #+#             */
/*   Updated: 2019/06/05 15:48:01 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int n;

	if (nb < 0)
		n = -nb;
	else
		n = nb;
	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar(n % 10 + '0');
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	while (a <= 99)
	{
		b = a + 1;
		while (b <= 99)
		{
			if (a < 10)
				ft_putchar('0');
			ft_putnbr(a);
			ft_putchar(' ');
			if (b < 10)
				ft_putchar('0');
			ft_putnbr(b);
			if (a != 98 | b != 99)
				write(1, ", ", 2);
			b++;
		}
		a++;
	}
}
