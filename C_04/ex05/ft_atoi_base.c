/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 02:44:08 by viroques          #+#    #+#             */
/*   Updated: 2019/06/13 18:03:12 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *base)
{
	int i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int		ft_is_space(char *base, int cas)
{
	int i;

	i = 0;
	if (cas == 0)
	{
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
	i = 0;
	if (cas == 1)
	{
		while (base[i] == '\t' || base[i] == '\n' || base[i] == '\v'
			|| base[i] == '\f' || base[i] == '\r' || base[i] == ' ')
			i++;
	}
	return (i);
}

int		ft_is_base(char *base)
{
	int i;
	int j;
	int len;

	j = 0;
	i = 0;
	len = ft_strlen(base);
	if (len <= 1)
		return (0);
	if (ft_is_space(base, 0) == 0)
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

int		ft_character_in_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int compt;
	int nb;
	int len_base;

	nb = 0;
	i = 0;
	compt = 1;
	len_base = ft_strlen(base);
	if (ft_is_base(base) == 0)
		return (0);
	i = ft_is_space(str, 1);
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			compt *= -1;
		i++;
	}
	while (ft_character_in_base(str[i], base) > -1)
		nb = nb * len_base + ft_character_in_base(str[i++], base);
	return (nb * compt);
}
