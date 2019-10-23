/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 00:07:46 by viroques          #+#    #+#             */
/*   Updated: 2019/06/25 20:09:52 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATOR_H
# define OPERATOR_H

int		ft_plus(int a, int b);
int		ft_minus(int a, int b);
int		ft_div(int a, int b);
int		ft_mod(int a, int b);
int		ft_mult(int a, int b);
typedef	int	(*t_pt)(int, int);

#endif
