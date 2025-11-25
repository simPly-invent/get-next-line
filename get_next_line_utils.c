/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:27:03 by mobenais          #+#    #+#             */
/*   Updated: 2025/11/25 21:00:48 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int	ft_checkback(char *base)
{
	int i = 0;
	while (base[i])
	{
		if(base[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *s1)
{
	int	i = 0;
	if (!s1)
		return 0;
	while(s1[i])
		i++;
	return (i);
}

char *ft_strcat(char *s1, char *s2)
{
	int	i = 0;
	int	len_s1 = ft_strlen(s1);

	while (s2[i])
	{
		s1[len_s1 + i] = s2[i];
		i++;
	}
	s1[len_s1 + i] = '\0';
	return (s1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));

	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	ptr[0] = '\0';
	ft_strcat(ptr, s1);
	ft_strcat(ptr, s2);
	free(s1);
	return (ptr);
}

char	*ft_strdup(char *s1)
{
	int len = ft_strlen(s1);
	char *ptr = malloc(len + 1);
	int i = 0;

	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char *str, int start, int len)
{
	char *ptr = malloc(len + 1);
	int i = 0;

	if (!ptr)
		return NULL;

	while (i < len && str[start + i])
	{
		ptr[i] = str[start + i];
		i++;
	}
	ptr[i] = '\0';

	return ptr;
}



/*
int main(void)
{
	char *s = "oui je suis malade";
	printf("string d'originre = %s\n", s);
	printf("string modifier = %s \n", ft_substr(s, 4, 8));
}
*/
