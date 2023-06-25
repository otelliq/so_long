/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:32:54 by otelliq           #+#    #+#             */
/*   Updated: 2023/04/19 23:51:08 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copie_1(t_map_data *m_d, char *path)
{
	int	fd;
	int	i;

	i = 0;
	m_d->map = malloc(m_d->row_count * sizeof(char *) + 1);
	fd = open(path, O_RDONLY);
	while (i < m_d->row_count)
	{
		m_d->map[i] = get_next_line(fd);
		i++;
	}
}

void	copie_2(t_map_data *m_d, char *path)
{
	int	fd;
	int	i;

	i = 0;
	m_d->map1 = malloc(m_d->row_count * sizeof(char *) + 1);
	fd = open(path, O_RDONLY);
	while (i < m_d->row_count)
	{
		m_d->map1[i] = get_next_line(fd);
		i++;
	}
}
