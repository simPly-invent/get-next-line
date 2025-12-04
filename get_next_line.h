/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenais <mobenais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:27:17 by mobenais          #+#    #+#             */
/*   Updated: 2025/12/04 16:34:30 by mobenais         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
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
int		check_back_index(char *str);
char	*ft_free_clean(char *ptr, char *buffer);
#endif
