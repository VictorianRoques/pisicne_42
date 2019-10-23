/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:34:24 by viroques          #+#    #+#             */
/*   Updated: 2019/06/20 16:08:52 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src, char *sep, int last)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (last == 0)
	{
		while (sep[j])
		{
			dest[i] = sep[j];
			i++;
			j++;
		}
	}
	else
		dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int i;
	int len;
	char*new_str;

	i = -1;
	len = 0;
	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	while (++i < size)
		len += ft_strlen(strs[i]);
	new_str = malloc(sizeof(char) * len + ft_strlen(sep) * (i - 1));
	i = -1;
	len = 0;
	while (++i < size)
	{
		if (i > 0)
			len += ft_strlen(strs[i - 1]) + ft_strlen(sep);
		if (i < size - 1)
			ft_strcpy(new_str + len, strs[i], sep, 0);
		else
			ft_strcpy(new_str + len, strs[i], sep, 1);
	}
	return (new_str);
}
