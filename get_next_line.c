/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenais <mobenais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:01:40 by mobenais          #+#    #+#             */
/*   Updated: 2025/11/21 18:54:27 by mobenais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "get_next_line.h"



char	*get_next_line(int fd)
{
	char 	*str;
	int	byte;

	byte = 1;
	
	while (byte = read(fd, )){}
}

int main(int argc, char **argv)
{
	int	fd;
	fd = open("text.txt", O_RDONLY);
	close(fd);
}
