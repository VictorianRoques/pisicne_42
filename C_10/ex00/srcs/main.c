/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 21:33:38 by viroques          #+#    #+#             */
/*   Updated: 2019/06/27 17:04:33 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define BUFF_SIZE 10

void	open_file(char *str)
{
	int		fd;
	char	buffer[BUFF_SIZE + 1];
	int		ret;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Cannot read file.\n", 18);
		close(fd);
		return ;
	}
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[ret] = '\0';
		write(1, buffer, ret);
	}
	close(fd);
}

int		main(int ac, char **argv)
{
	if (ac < 2)
	{
		write(2, "File name missing.\n", 19);
		return (0);
	}
	if (ac > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (0);
	}
	open_file(argv[1]);
}
