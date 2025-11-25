/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenais <mobenais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:01:40 by mobenais          #+#    #+#             */
/*   Updated: 2025/11/25 01:06:21 by mobenais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "get_next_line.h"

int	there_is_backslash_n(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == '\n'){
			printf("newline found");
			return (1);
		}
		i++;
	}
	return (0);
}

int	indexofbackslash_n(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] == 'n')
			return (i);
		i++;
	}
	return (-1);
}

int main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY);
	char buffer[BUFFER_SIZE];
	int byte;

	while((byte = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[byte] = '\0';
		if (indexofbackslash_n(buffer) >= 0)
			write(1, buffer, indexofbackslash_n(buffer) + 1);
	//	write(1, buffer, byte);	
	}
	close(fd);
}
