/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenais <mobenais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:01:40 by mobenais          #+#    #+#             */
/*   Updated: 2025/12/01 18:01:55 by mobenais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_back_index(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	ft_bzero(char *str ,int len)
{
	int	i;

	i = 0;
	while(i < len)
	{
		str[i] = '\0';
		i++;
	}
}

static void	ft_strmove(char *dest, char *src, int offset)
{
	int i = 0;
	
	while (src[i + offset])
	{
		dest[i] = src[i + offset];
		src[i + offset] = '\0';
		i++;
	}
	dest[i] = '\0';
}

char	*get_next_line(int fd)
{
	int res;
	int len;
	char *rslt;
	static char buffer[BUFFER_SIZE + 1];

	res = BUFFER_SIZE;
	rslt = NULL;
	rslt = ft_strjoin(rslt, buffer);
	while (res > 0 && check_back_index(buffer) == -1)
	{
		res = read(fd, buffer, BUFFER_SIZE);
		rslt = ft_strjoin(rslt, buffer);
		//printf("rslt: %s, buffer: %s\n", rslt, buffer);
	}
	len = check_back_index(buffer);
	ft_strmove(buffer, buffer, len + 1);
	if (res <= 0 && rslt[0] && !buffer[0])
	{
		ft_bzero(buffer, BUFFER_SIZE);
		return (rslt);
	}
	if (!res && !rslt[0])
	{
		free(rslt);
		return (NULL);
	}
	return (rslt);
}

int main(int argc, char **argv)
{
	char *ptr;
	int fd;
	ptr = "";
	fd = open(argv[1], O_RDONLY);
	while (ptr)
	{
		ptr = get_next_line(fd);
		printf("%s", ptr);
		free(ptr);
	}
	close(fd);
}
