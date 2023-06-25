/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 02:59:02 by otelliq           #+#    #+#             */
/*   Updated: 2023/04/20 02:59:20 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_line_detected(char *res)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (res[i])
	{
		if (res[i] == '\n')
			n++;
		if (res[i] == '\n' && res[i + 1] == '\n')
		{
			write(2, "Error\n", 6);
			free(res);
			exit(1);
		}
		i++;
	}
}

void	check_newlines(char **av)
{
	int		fd;
	int		byte_read;
	char	*buffer;
	char	*res;

	byte_read = 1;
	res = ft_calloc(1, 1);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	fd = open(av[1], O_RDONLY);
	while (byte_read > 0)
	{
		byte_read = read (fd, buffer, BUFFER_SIZE);
		buffer[byte_read] = '\0';
		res = ft_strjoin (res, buffer);
	}
	new_line_detected (res);
	free (buffer);
	free (res);
}

char	*ft_calloc(int count, int size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*((unsigned char *)b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}
