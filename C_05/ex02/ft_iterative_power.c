/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 18:36:30 by viroques          #+#    #+#             */
/*   Updated: 2019/06/16 08:43:39 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int result;
	int i;

	result = 1;
	i = 1;
	if (power < 0)
		return (0);
	if (power == 1)
		return (nb);
	while (i <= power)
	{
		result = result * nb;
		i++;
	}
	return (result);
}
