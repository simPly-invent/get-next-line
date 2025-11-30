/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:01:40 by mobenais          #+#    #+#             */
/*   Updated: 2025/11/29 13:55:56 by mobenais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*_fill_line_buffer(int fd, char *left_c, char *buffer);
char	*_set_line(char *line_buffer);
char	*_set_line(char *line_buffer);


static char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

static char	*ft_manage_str(int fd, char *left_c, char *buffer)
{
	
	ssize_t	b_read;
	char	*tmp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(left_c);
			return (NULL);
		}
		else if (b_read == 0)
			break ;
		buffer[b_read] = 0;
		if (!left_c)
			left_c = ft_strdup("");
		tmp = left_c;
		left_c = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_c);
}

static char	*ft_check_str(char *line_buffer)
{
	
    char    *extract_line;
    ssize_t    i;
    
    i = 0;
    while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
        i++;
    if (line_buffer[i] == 0 || line_buffer[1] == 0)
        return (NULL);
       extract_line = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
    if (extract_line == 0)
    {
        free(extract_line);
        extract_line = NULL;
    } 
    line_buffer[i + 1] = 0;
    return (extract_line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*extract_line;
	char		*buffer;
	
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stash);
		free(buffer);
		stash = NULL;
		buffer = NULL;
		write(1, "nothing to return", 17);
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	extract_line = ft_manage_str(fd, stash, buffer);
	free(buffer);
	buffer = NULL;
	if (!extract_line)
		return (NULL);
	stash = ft_check_str(extract_line);
	return (extract_line);
}
/*
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
*/
