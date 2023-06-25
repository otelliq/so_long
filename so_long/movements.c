/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 01:54:24 by otelliq           #+#    #+#             */
/*   Updated: 2023/04/19 10:38:10 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_map_data *m_d)
{
	m_d->c = collectible_checker(m_d);
	if (m_d->map[m_d->player_y - 1][m_d->player_x] == '1')
	{
		m_d->map[m_d->player_y][m_d->player_x] = 'P';
		print_map(m_d);
	}
	else if (m_d->map[m_d->player_y - 1][m_d->player_x] == '0')
	{
		up(m_d);
	}
	else if (m_d->map[m_d->player_y - 1][m_d->player_x] == 'C')
	{
		m_d->c--;
		up(m_d);
	}
	else if (m_d->map[m_d->player_y - 1][m_d->player_x] == 'E' && m_d->c == 0)
	{
		congrats();
		exit(0);
	}
}

void	move_down(t_map_data *m_d)
{
	m_d->c = collectible_checker(m_d);
	if (m_d->map[m_d->player_y + 1][m_d->player_x] == '1')
	{
		m_d->map[m_d->player_y][m_d->player_x] = 'P';
		print_map(m_d);
	}
	else if (m_d->map[m_d->player_y + 1][m_d->player_x] == '0')
	{
		down(m_d);
	}
	else if (m_d->map[m_d->player_y + 1][m_d->player_x] == 'C')
	{
		m_d->c--;
		down(m_d);
	}
	else if (m_d->map[m_d->player_y + 1][m_d->player_x] == 'E' && m_d->c == 0)
	{
		congrats();
		exit(0);
	}
}

void	move_right(t_map_data *m_d)
{
	m_d->c = collectible_checker(m_d);
	if (m_d->map[m_d->player_y][m_d->player_x + 1] == '1')
	{
		m_d->map[m_d->player_y][m_d->player_x] = 'P';
		print_map(m_d);
	}
	else if (m_d->map[m_d->player_y][m_d->player_x + 1] == 'C')
	{
		m_d->c--;
		right(m_d);
	}
	else if (m_d->map[m_d->player_y][m_d->player_x + 1] == '0')
	{
		right(m_d);
	}
	else if (m_d->map[m_d->player_y][m_d->player_x + 1] == 'E' && m_d->c == 0)
	{
		congrats();
		exit(0);
	}
}

void	move_left(t_map_data *m_d)
{
	m_d->c = collectible_checker(m_d);
	if (m_d->map[m_d->player_y][m_d->player_x - 1] == 'E' && m_d->c == 0)
	{
		congrats();
		exit(0);
	}
	else if (m_d->map[m_d->player_y][m_d->player_x - 1] == '1')
	{
		m_d->map[m_d->player_y][m_d->player_x] = 'P';
		print_map(m_d);
	}
	else if (m_d->map[m_d->player_y][m_d->player_x - 1] == 'C')
	{
		m_d->c--;
		left(m_d);
	}
	else if (m_d->map[m_d->player_y][m_d->player_x - 1] == '0')
	{
		left(m_d);
	}
}
