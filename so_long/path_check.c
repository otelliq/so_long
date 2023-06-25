/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:49:24 by otelliq           #+#    #+#             */
/*   Updated: 2023/04/19 23:45:17 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	path_checker(char **map, int x, int y)
{
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'P' && map[y + 1][x] != 'E')
	{
		map[y + 1][x] = 'P';
		path_checker(map, x, y + 1);
	}
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'P' && map[y - 1][x] != 'E')
	{
		map[y - 1][x] = 'P';
		path_checker(map, x, y - 1);
	}
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'P' && map[y][x - 1] != 'E')
	{
		map[y][x - 1] = 'P';
		path_checker(map, x - 1, y);
	}
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'P' && map[y][x + 1] != 'E')
	{
		map[y][x + 1] = 'P';
		path_checker(map, x + 1, y);
	}
}

int	path_checker_result(t_map_data *m_d)
{
	int	i;
	int	j;

	i = 0;
	while (i < m_d->row_count)
	{
		j = 0;
		while (j < m_d->col_count)
		{
			if (m_d->map1[i][j] == 'C')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	collectible_counter(t_map_data *m_d)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < m_d->row_count)
	{
		j = 0;
		while (j < m_d->col_count)
		{
			if (m_d->map[i][j] == 'C')
			{
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}
