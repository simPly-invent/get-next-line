/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:01:40 by mobenais          #+#    #+#             */
/*   Updated: 2025/12/03 21:15:14 by mohamed          ###   ########.fr       */
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
		i++;
	}
	dest[i] = '\0';
}

char	*get_next_line(int fd)
{
	int byte;
	char *rslt;
	static char buffer[BUFFER_SIZE + 1];

	byte = 0;
	rslt = NULL;
	while (check_back_index(buffer) == -1)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte < 0 && buffer[0])
		{
			return (buffer);
		}
		rslt = ft_strjoin(rslt, buffer);
	}
	rslt = ft_strjoin(rslt, buffer);
	ft_strmove(buffer, buffer, check_back_index(buffer) + 1);
	return (rslt);
}

int main(int argc, char **argv)
{
	char *ptr;
	int fd;
	int	i = 1;
	ptr = "";
	fd = open(argv[1], O_RDONLY);
	// while (ptr)
	// {
		ptr = get_next_line(fd);
		printf("%s", ptr);
		free(ptr);
	//  	i++;
	// }
	close(fd);
}
