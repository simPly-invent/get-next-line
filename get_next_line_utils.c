/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenais <mobenais@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:27:03 by mobenais          #+#    #+#             */
/*   Updated: 2025/11/21 11:31:37 by mobenais         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_checkback(char *base)
{
	char	back;
	int		i;
	
	i = 0;
	back = '\0';
	while (base[sei])
	{
		if(base[i] == back)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *s1)
{
	int	i;

	i = 0;
	while(s1[i])
		i++;
	return (i);
}

char *ft_strcat(char *s1, char *s2)
{
	int	i;
	int	len_s1;
	int	len_s2;

	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
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
	int		i;

	i = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1):
	if (!ptr)
	 return (NULL);
	ft_strcat(ptr, s1);
	ft_strcat(ptr, s2);
	return (ptr);
}
