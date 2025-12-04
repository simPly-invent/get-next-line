/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenais <mobenais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:27:03 by mobenais          #+#    #+#             */
/*   Updated: 2025/12/04 10:31:40 by mobenais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
    int i = 0;
    if (!str)
        return (0);
    while(str[i])
        i++;
    return (i);
}

char	*ft_strcat(char *dst, char *src)
{
	int	i;
	int	dst_len;

	i = 0;
	dst_len = ft_strlen(dst);
	while (src[i] && src[i] != '\n')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
    if( src[i] == '\n')
    {
        dst[dst_len + i] = src[i];
				i++;
    }
	dst[dst_len + i] = '\0';
	return (dst);
}

char *ft_strdup(char *str, int len)
{
    char *ptr;
    int i;

    i = 0;
    ptr = malloc(sizeof(str) * (ft_strlen(str) + 1));
    if(!str)
        return (NULL);
    if (!ptr)
        return (NULL);
    while (str[i] && i <= len)
    {
        ptr[i] = str[i];
        i++;
    }
    ptr[i] = '\0';
    return (ptr);
}

char *ft_strjoin(char *dst, char *src)
{
    int len;
    char *ptr;

    if (!dst)
    {
        dst = malloc(1);
        if(!dst)
            return (NULL);
        dst[0] = '\0';
    }
    if (!src)
        return (dst);
    len = (ft_strlen(dst) + ft_strlen(src));
    ptr = malloc(sizeof(char) * (len + 1));
    if (!ptr)
    {
        free(dst);
        return (NULL);
    }
    ft_bzero(ptr, len + 1);
    if(dst)
        ft_strcat(ptr, dst);
    if(dst)
        free(dst);
    ft_strcat(ptr, src);
    return (ptr);
}
