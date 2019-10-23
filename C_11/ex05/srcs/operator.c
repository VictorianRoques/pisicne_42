/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_fct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 00:03:29 by viroques          #+#    #+#             */
/*   Updated: 2019/06/25 23:53:37 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_plus(int a, int b)
{
	return (a + b);
}

int		ft_minus(int a, int b)
{
	return (a - b);
}

int		ft_div(int a, int b)
{
	if (b == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	return (a / b);
}

int		ft_mod(int a, int b)
{
	if (b == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	return (a % b);
}

int		ft_mult(int a, int b)
{
	return (a * b);
}
