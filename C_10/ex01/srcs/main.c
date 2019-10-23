/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 16:34:46 by viroques          #+#    #+#             */
/*   Updated: 2019/06/27 17:03:29 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/buffer.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_print_error(char *str, char *name_file)
{
	write(2, name_file, ft_strlen(name_file));
	write(2, ": ", 2);
	write(2, str, ft_strlen(str));
	write(2, ": ", 2);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
}

void	open_file(char *str, char *name_file)
{
	int		fd;
	char	buff[BUFF_SIZE + 1];
	int		ret;

	errno = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_print_error(str, name_file);
		close(fd);
		return ;
	}
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
		{
			ft_print_error(str, name_file);
			close(fd);
			return ;
		}
		buff[ret] = '\0';
		write(1, buff, ft_strlen(buff));
	}
	close(fd);
}

int		main(int ac, char **argv)
{
	int		i;
	int		ret;
	char	buff[BUFF_SIZE + 1];

	i = 1;
	if (ac == 1)
	{
		while ((ret = read(STDIN_FILENO, buff, BUFF_SIZE)))
		{
			buff[ret] = '\0';
			write(1, buff, ft_strlen(buff));
		}
	}
	while (i < ac)
	{
		open_file(argv[i], basename(argv[0]));
		i++;
	}
}
