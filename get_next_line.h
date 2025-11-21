/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenais <mobenais@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:27:17 by mobenais          #+#    #+#             */
/*   Updated: 2025/11/21 11:07:44 by mobenais         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char 	*get_next_line(int fd);
int		checkback(char *base);
int		ft_strlen(char *s1);
char 	*strcat(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);


#endif
