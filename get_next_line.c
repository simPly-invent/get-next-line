/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenais <mobenais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:01:40 by mobenais          #+#    #+#             */
/*   Updated: 2025/12/04 10:51:24 by mobenais         ###   ########.fr       */
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
	return (i);
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
		i++;
	}
	dest[i] = '\0';
}

int	reading(char *buffer, int fd)
{
	int	byte;
	byte = read(fd, buffer, BUFFER_SIZE);
	if (byte >= 0)
		buffer[byte] = 0;
	else
		buffer[0] = 0;
	return (byte);
}

char	*get_next_line(int fd)
{
	int byte;
	char *rslt;
	static char buffer[BUFFER_SIZE + 1] = {0};

	byte = 1;
	rslt = NULL;
	while (byte > 0)
	{
		if (!buffer[0])
		{
			byte = reading(buffer, fd);
		}
		if (byte < 0)
		{
			ft_bzero(buffer, ft_strlen(buffer));
			free(rslt);
			return (NULL);
		}
		rslt = ft_strjoin(rslt, buffer);
		if (!rslt)
			return (NULL);
		if (check_back_index(buffer) != ft_strlen(buffer))
		{
			ft_strmove(buffer, buffer, check_back_index(buffer) + 1);
			break ;
		}
		else
		{
			ft_bzero(buffer, ft_strlen(buffer));
		}
	}
	if (byte <= 0 && ft_strlen(rslt) == 0)
	{
		free(rslt);
		return NULL;
	}
	return (rslt);
}

// int main(int argc, char **argv)
// {
// 	char *ptr;
// 	int fd;
// 	int	i = 1;
// 	ptr = "";
// 	fd = open(argv[1], O_RDONLY);
// 	ptr = get_next_line(fd);
// 	free(ptr);
// 	ptr = get_next_line(fd);
// 	free(ptr);
// 	close(fd);
// 	ptr = get_next_line(fd);
// 	printf("%s\n", ptr);
// 	free(ptr);
// }
