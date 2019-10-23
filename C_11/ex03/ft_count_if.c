/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 23:23:15 by viroques          #+#    #+#             */
/*   Updated: 2019/06/24 23:50:07 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int length, int (*f)(char*))
{
	int i;
	int compt;

	compt = 0;
	i = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			compt++;
		i++;
	}
	return (compt);
}
