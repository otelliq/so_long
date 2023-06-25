/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 00:46:11 by otelliq           #+#    #+#             */
/*   Updated: 2023/04/19 07:06:38 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line_counter(char **av)
{
	int		i;
	char	*str;
	int		fd;

	i = 0;
	fd = open(av[1], O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		free (str);
		str = get_next_line(fd);
		i++;
	}
	free (str);
	return (i);
}

int	column_counter(char *line)
{
	int	i;

	i = 0;
	while (line[i] != 0 && line[i] != '\n')
		i++;
	return (i);
}
