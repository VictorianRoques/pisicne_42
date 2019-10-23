/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:55:23 by viroques          #+#    #+#             */
/*   Updated: 2019/06/11 22:15:47 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

void	ft_print_hexa_number(unsigned int nb, int i)
{
	char *base;

	base = "0123456789abcdef";
	if (nb >= 16)
		ft_print_hexa_number(nb / 16, ++i);
	if (i == 1)
		ft_putchar('0');
	ft_putchar(base[nb % 16]);
}

void	ft_print_hex(unsigned char c)
{
	char *base;

	base = "0123456789abcdef";
	ft_putchar(base[c / 16]);
	ft_putchar(base[c % 16]);
}

void	ft_print_line(char *str, unsigned int size)
{
	unsigned int i;

	write(1, "0000001", 7);
	i = -1;
	ft_print_hexa_number((unsigned int)str, 1);
	write(1, ": ", 2);
	while (++i < 16)
	{
		if (str[i] && i < size)
			ft_print_hex(str[i]);
		else
			write(1, "  ", 2);
		if (i % 2 == 1)
			write(1, " ", 1);
	}
	i = -1;
	while (++i < 16)
	{
		if (str[i] > 31 && str[i] < 127 && i < size)
			ft_putchar(str[i]);
		else if (str[i] <= 31 && i < size)
			write(1, ".", 1);
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int position;
	unsigned int i;
	unsigned int tour;

	position = 0;
	tour = size / 16;
	if (size % 16 == 0)
		tour -= 1;
	i = 0;
	if (size == 0)
		return (0);
	while (i <= tour)
	{
		if (i == tour && size % 16 > 0)
			ft_print_line(addr + position, size % 16);
		else
		{
			ft_print_line(addr + position, 16);
			position += 16;
		}
		i++;
	}
	return (addr);
}
