/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 18:09:16 by viroques          #+#    #+#             */
/*   Updated: 2019/06/13 18:12:55 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

unsigned int	ft_strlen(char *base)
{
	unsigned int i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int				ft_is_space(char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == '\t'
				|| base[i] == '\n' || base[i] == '\v' || base[i] == '\f'
				|| base[i] == '\r' || base[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

int				ft_is_base(char *base)
{
	int i;
	int j;
	int len;

	j = 0;
	i = 0;
	len = ft_strlen(base);
	if (len <= 1)
		return (0);
	if (ft_is_space(base) == 0)
		return (0);
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j] && base[j] != '\0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void			ft_putnbr_base(int nbr, char *base)
{
	unsigned int n;
	unsigned int max_base;

	max_base = ft_strlen(base);
	if (ft_is_base(base) == 0)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		n = -nbr;
	}
	else
		n = nbr;
	if (n >= max_base)
		ft_putnbr_base(n / max_base, base);
	ft_putchar(base[n % max_base]);
}
