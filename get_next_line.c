/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenais <mobenais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:01:40 by mobenais          #+#    #+#             */
/*   Updated: 2025/12/05 07:38:22 by mobenais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_back_index(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

void	ft_bzero(char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		str[i] = '\0';
		i++;
	}
}

static void	ft_strmove(char *dest, char *src, int offset)
{
	int	i;

	i = 0;
	while (src[i + offset])
	{
		dest[i] = src[i + offset];
		i++;
	}
	dest[i] = '\0';
}

int	reading(char *buffer, int fd)
{
	int	byte_read;

	byte_read = read(fd, buffer, BUFFER_SIZE);
	if (byte_read >= 0)
		buffer[byte_read] = 0;
	else
		buffer[0] = 0;
	return (byte_read);
}

char	*get_next_line(int fd)
{
	t_gnl		var;
	static char	buffer[BUFFER_SIZE + 1];

	var.byte_read = 1;
	var.extracted_line = NULL;
	while (var.byte_read > 0)
	{
		if (!buffer[0])
			var.byte_read = reading(buffer, fd);
		if (var.byte_read < 0)
			return (ft_free_clean(var.extracted_line, buffer));
		var.extracted_line = ft_strjoin(var.extracted_line, buffer);
		if (!var.extracted_line)
			return (NULL);
		if (check_back_index(buffer) != ft_strlen(buffer))
		{
			ft_strmove(buffer, buffer, check_back_index(buffer) + 1);
			break ;
		}
		else
			ft_bzero(buffer, ft_strlen(buffer));
	}
	if (var.byte_read <= 0 && ft_strlen(var.extracted_line) == 0)
		return (ft_free_clean(var.extracted_line, buffer));
	return (var.extracted_line);
}

// int main(int argc, char **argv)
// {
// 	(void)argc;
// 	char *ptr;
// 	int fd;
// 	ptr = "";
// 	fd = open(argv[1], O_RDONLY);
// 	while (ptr)
// 	{
// 		ptr = get_next_line(fd);
// 		printf("%s", ptr);
// 		free(ptr);
// 	}
// 	ptr = get_next_line(fd);
// 	free(ptr);

// }
