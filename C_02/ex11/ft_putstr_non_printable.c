/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 02:11:21 by viroques          #+#    #+#             */
/*   Updated: 2019/06/11 19:26:32 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

void	ft_print_hexa(unsigned char c)
{
	char *tab;

	tab = "0123456789abcdef";
	ft_putchar(tab[c / 16]);
	ft_putchar(tab[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] == 127)
		{
			ft_putchar('\\');
			ft_print_hexa(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
