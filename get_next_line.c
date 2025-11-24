/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenais <mobenais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:01:40 by mobenais          #+#    #+#             */
/*   Updated: 2025/11/24 17:07:36 by mobenais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "get_next_line.h"

int	is_backslash(char *s)
{
	int i = -1;
	while (s[++i])
		if(s[i] == '\n')
			return 1;
	return (0);
}

int main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY);
	char buffer[15];
	int byte;

	while ((byte = read(fd, buffer, 15)) > 0)
	{
		buffer[byte] = '\0';
		while (is_backslash(buffer) == 0)
		{
			ft_strdup(buffer); 
		}
	}
	close(fd);
	return 0;
}
