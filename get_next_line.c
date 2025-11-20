/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenais <mobenais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:01:40 by mobenais          #+#    #+#             */
/*   Updated: 2025/11/20 15:24:29 by mobenais         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

char	*get_next_line(int fd)
{

}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	read_all_file(int fd, int size)
{
	int		res;
	char	buf[4096];

	res = read(fd, buf, size);
	while (res > 0)
	{
		write(1, buf, res);
		return (1);
	}
	if (res < 0)
	{
		ft_putstr_fd("Cannot read file.\n", 2);
		return (1);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	fd;
	int	size;

	size = 4096;
	if (argc == 1)
	{
		ft_putstr_fd("File name missing.\n", 2);
		return (1);
	}
	if (argc > 2)
	{
		ft_putstr_fd("Too many arguments.\n", 2);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	read_all_file(fd, size);
	close (fd);
	return (1);
}

