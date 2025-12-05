/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenais <mobenais@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 09:28:57 by mobenais          #+#    #+#             */
/*   Updated: 2025/12/05 09:29:01 by mobenais         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_gnl
{
	int		byte_read;
	char	*extracted_line;
}			t_gnl;

int		ft_strlen(char *str);
char	*ft_strjoin(char *dst, char *src);
char	*get_next_line(int fd);
void	ft_bzero(char *str, int len);
int		isback(char *str);
char	*ft_free_clean(char *ptr, char *buffer);
#endif
