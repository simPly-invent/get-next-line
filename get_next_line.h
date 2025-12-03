/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:27:17 by mobenais          #+#    #+#             */
/*   Updated: 2025/12/03 13:34:46 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int    ft_strlen(char *str);
char	*ft_strcat(char *dst, char *src);
char  *ft_strjoin(char *dst, char *src);
char	*get_next_line(int fd);
void	ft_bzero(char *str ,int len);
int   check_back_index(char *str);
char  *ft_strdup(char *str, int len);
#endif
