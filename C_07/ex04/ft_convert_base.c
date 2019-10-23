/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:42:06 by viroques          #+#    #+#             */
/*   Updated: 2019/06/24 17:49:45 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_atoi_base(char *str, char *bas);

int			ft_is_base(char *base);

int			ft_compt(int nbr, char *base, int negativ)
{
	unsigned int	len_base;
	int				compt;
	unsigned int	nb;

	compt = 0;
	len_base = 0;
	if (negativ == 1)
	{
		nb = -nbr;
		compt++;
	}
	else
		nb = nbr;
	while (base[len_base])
		len_base++;
	while (nb >= len_base)
	{
		nb = nb / len_base;
		compt++;
	}
	return (++compt);
}

int			ft_putnbr_base(int n, char *base, char *str, int i)
{
	unsigned int	len_base;
	unsigned int	nb;

	len_base = 0;
	while (base[len_base])
		len_base++;
	if (n < 0)
		nb = -n;
	else
		nb = n;
	if (nb >= len_base)
		ft_putnbr_base(nb / len_base, base, str, i - 1);
	str[i] = base[nb % len_base];
	return (i);
}

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int				nb;
	char			*str;
	int				new_len;
	int				negativ;

	negativ = 0;
	if (!(ft_is_base(base_from) && ft_is_base(base_to)))
		return (0);
	nb = ft_atoi_base(nbr, base_from);
	if (nb < 0)
		negativ = 1;
	new_len = ft_compt(nb, base_to, negativ);
	if (!(str = malloc(sizeof(char) * (new_len + 1))))
		return (NULL);
	ft_putnbr_base(nb, base_to, str, new_len - 1);
	if (negativ == 1)
		str[0] = '-';
	str[new_len] = '\0';
	return (str);
}
