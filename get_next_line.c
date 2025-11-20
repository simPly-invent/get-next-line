/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenais <mobenais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:01:40 by mobenais          #+#    #+#             */
/*   Updated: 2025/11/20 13:09:51 by mobenais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{

}

void	print_char(char *s)
{
	write(1, s, ft_strlen(s));
}

int main(int argc, char **argv)
{
	int fd = open(argv[2], O_RDONLY);
	int buffer = 1000;
	char read;


	while ((read = )
}
