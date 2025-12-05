/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenais <mobenais@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 09:29:22 by mobenais          #+#    #+#             */
/*   Updated: 2025/12/05 09:29:26 by mobenais         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	value_min(int a, int b);

char	*ft_free_clean(char *ptr, char *buffer)
{
	if (buffer)
		ft_bzero(buffer, ft_strlen(buffer));
	free(ptr);
	return (NULL);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

static void	*ft_memcpy(void *dest, void *src, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	i = 0;
	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	while (i < len)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_strjoin(char *dst, char *src)
{
	int		s1;
	int		s2;
	char	*ptr;

	s1 = ft_strlen(dst);
	s2 = value_min(isback(src) + 1, ft_strlen(src));
	if (!dst)
	{
		dst = malloc(sizeof(char));
		if (!dst)
			return (NULL);
		dst[0] = '\0';
	}
	ptr = malloc(sizeof(char) * (s1 + s2 + 1));
	if (!ptr)
	{
		free(dst);
		return (NULL);
	}
	ft_memcpy(ptr, dst, s1);
	ft_memcpy(&ptr[s1], src, s2);
	ptr[s1 + s2] = '\0';
	free(dst);
	return (ptr);
}

static int	value_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
