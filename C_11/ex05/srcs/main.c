/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculatrice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 00:10:55 by viroques          #+#    #+#             */
/*   Updated: 2019/06/26 23:44:19 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/operator.h"

void	ft_putnbr(int nb)
{
	unsigned int	n;
	char			c;

	if (nb < 0)
	{
		write(1, "-", 1);
		n = -nb;
	}
	else
		n = nb;
	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int		ft_atoi(char *str)
{
	int i;
	int signe;
	int nb;

	signe = 1;
	nb = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\n' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * signe);
}

t_pt	ft_op(char op)
{
	if (op == '+')
		return (ft_plus);
	if (op == '-')
		return (ft_minus);
	if (op == '/')
		return (ft_div);
	if (op == '*')
		return (ft_mult);
	if (op == '%')
		return (ft_mod);
	return (NULL);
}

int		ft_calculatrice(int a, int b, int (*f)(int, int))
{
	return (f(a, b));
}

int		main(int ac, char **argv)
{
	int	nb;
	int (*pt)(int, int);
	int	i;

	i = 0;
	nb = 0;
	pt = ft_op(argv[2][0]);
	if (ac != 4)
		return (0);
	while (argv[2][i])
		i++;
	if (pt == NULL || i > 1)
	{
		ft_putnbr(nb);
		write(1, "\n", 1);
		return (0);
	}
	nb = ft_calculatrice(ft_atoi(argv[1]), ft_atoi(argv[3]), pt);
	if (ft_atoi(argv[3]) == 0 && (pt == ft_div || pt == ft_mod))
		return (0);
	ft_putnbr(nb);
	write(1, "\n", 1);
}
