/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 23:06:54 by viroques          #+#    #+#             */
/*   Updated: 2019/06/20 15:39:15 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int i;
	int	*tab;

	i = 0;
	tab = NULL;
	if (min >= max)
		return (tab);
	tab = malloc(sizeof(int) * (max - min));
	while (i < max - min)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}
