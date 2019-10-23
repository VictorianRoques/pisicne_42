/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 22:29:23 by viroques          #+#    #+#             */
/*   Updated: 2019/06/26 17:41:39 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *map;

	i = 0;
	if (!(map = malloc(sizeof(int) * length)))
		return (NULL);
	while (i < length)
	{
		map[i] = f(tab[i]);
		i++;
	}
	return (map);
}
