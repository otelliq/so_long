/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:19:46 by otelliq           #+#    #+#             */
/*   Updated: 2023/01/31 02:52:08 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_first_line(char *s)
{
	int		i;
	char	*line;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line || !s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_rest_line(char *s)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\0' || (s[i + 1] == '\0' && s[i] == '\n'))
		return (0);
	rest = malloc((ft_strlen(s) - i + 1));
	i++;
	while (s[i])
		rest[j++] = s[i++];
	rest[j] = '\0';
	return (rest);
}

char	*ft_read_line(int fd, char *s)
{
	char	*buffer;
	int		i;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	while (1)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(s);
			free(buffer);
			return (0);
		}
		if (i == 0)
			break ;
		buffer[i] = '\0';
		s = ft_strjoin(s, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*line;
	char		*rest;

	s = ft_read_line(fd, s);
	rest = s;
	if (!s)
	{
		free(s);
		return (0);
	}
	line = get_first_line(s);
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	s = get_rest_line(s);
	free(rest);
	return (line);
}
