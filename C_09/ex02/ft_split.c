/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 00:22:54 by viroques          #+#    #+#             */
/*   Updated: 2019/06/22 05:46:39 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_sep(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_compt_string(char *str, char *charset)
{
	int i;
	int string;

	i = 0;
	string = 0;
	while (str[i])
	{
		while (ft_is_sep(str[i], charset) == 1)
			i++;
		while (ft_is_sep(str[i], charset) == 0 && str[i])
			i++;
		while (ft_is_sep(str[i], charset) == 1)
			i++;
		string++;
	}
	return (string);
}

void	ft_compt_char(char *str, char *charset, char **tab)
{
	int i;
	int c;
	int string;

	i = 0;
	c = 0;
	string = 0;
	while (str[i])
	{
		while (ft_is_sep(str[i], charset) == 1)
			i++;
		while (ft_is_sep(str[i], charset) == 0 && str[i])
		{
			c++;
			i++;
		}
		while (ft_is_sep(str[i], charset) == 1)
			i++;
		tab[string] = (char *)malloc(sizeof(char) * c + 1);
		c = 0;
		string++;
	}
}

char	**ft_fill_string(char *str, char *charset, char **tab)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (str[k])
	{
		while (str[k] && ft_is_sep(str[k], charset) == 0)
		{
			tab[i][j] = str[k];
			j++;
			k++;
			if (str[k] == '\0' || ft_is_sep(str[k], charset) == 1)
			{
				tab[i++][j] = '\0';
				j = 0;
			}
		}
		if (str[k])
			k++;
	}
	tab[i] = 0;
	return (tab);
}

char	**ft_split(char *str, char *charset)
{
	char **tab;

	tab = (char **)malloc(sizeof(char *) * ft_compt_string(str, charset) + 1);
	ft_compt_char(str, charset, tab);
	tab = ft_fill_string(str, charset, tab);
	return (tab);
}
