/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 20:24:43 by viroques          #+#    #+#             */
/*   Updated: 2019/06/17 20:50:06 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int i;

	if (nb % 2 == 0)
	{
		i = 0;
	}
	else
		i = 1;
	while (i * i <= nb && nb <= 2147395600)
	{
		if (i * i == nb)
			return (i);
		i += 2;
	}
	return (0);
}