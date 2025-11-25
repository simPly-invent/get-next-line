/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:01:40 by mobenais          #+#    #+#             */
/*   Updated: 2025/11/25 21:22:03 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "get_next_line.h"

int	indexofbackslash_n(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char *stash = NULL;
	char	buffer[BUFFER_SIZE + 1];
	int		byte;
	int		i;
	char	*extract_line;
	char	*newstash;

	while ((byte = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[byte] = '\0';
		stash = ft_strjoin(stash, buffer);
		i = indexofbackslash_n(stash);
		if (i >= 0)
		{
			extract_line = ft_substr(stash, 0, i + 1);
			newstash = ft_substr(stash, i + 1, ft_strlen(stash) - (i + 1));
			free(stash);
			stash = newstash;
			return (extract_line);
		}
	}
	if (stash && *stash)
	{
		extract_line = ft_strdup(stash);
		free(stash);
		stash = NULL;
		return extract_line;
	}
	free(stash);
	stash = NULL;
	return NULL;
}

int main(int argc, char **argv)
{
	int	fd = open(argv[1], O_RDONLY);
	char	*buffer;
	while((buffer = get_next_line(fd)))
	{
		printf("%s", buffer);
		free(buffer);
	}
	close(fd);
}
