/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 04:51:03 by otelliq           #+#    #+#             */
/*   Updated: 2023/04/20 02:49:35 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	walls_checker(t_map_data *m_d)
{
	int	i;

	i = 0;
	while (i < m_d -> col_count)
	{
		if (m_d->map[0][i] != '1')
			return (0);
	i++;
	}
	i = 0;
	while (i < m_d -> col_count)
	{
		if (m_d->map[m_d -> row_count - 1][i] != '1')
			return (0);
	i++;
	}
	i = 1;
	while (i < m_d -> row_count -1)
	{
		if (m_d->map[i][0] != '1' || m_d->map[i][m_d-> col_count - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	rectangle_check(t_map_data *m_d)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = ft_strlen(m_d->map[0]);
	while (i < m_d -> row_count - 1)
	{
		j = ft_strlen(m_d->map[i]);
		if (j != size)
			return (0);
		i++;
	}
	return (1);
}

int	collectible_checker(t_map_data *m_d)
{
	int	i;
	int	j;

	i = 0;
	while (i < m_d->row_count)
	{
		j = 0;
		while (j < m_d->col_count)
		{
			if (m_d->map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	player_checker(t_map_data *m_d)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	while (i < m_d->row_count)
	{
		j = 0;
		while (j < m_d->col_count)
		{
			if (m_d->map[i][j] == 'P')
			{
				p++;
				m_d->player_y = i;
				m_d->player_x = j;
			}
			j++;
		}
		i++;
	}
	if (p != 1)
		return (0);
	return (1);
}

int	exit_checker(t_map_data *m_d)
{
	int	i;
	int	j;
	int	e;

	i = 0;
	e = 0;
	while (i < m_d->row_count)
	{
		j = 0;
		while (j < m_d->col_count)
		{
			if (m_d->map[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	if (e != 1)
		return (0);
	return (1);
}
