/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 02:13:43 by otelliq           #+#    #+#             */
/*   Updated: 2023/04/19 10:37:40 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_map_data *m_d)
{
	m_d->map[m_d->player_y - 1][m_d->player_x] = 'P';
	m_d->map[m_d->player_y][m_d->player_x] = '0';
	m_d->player_y--;
	print_map(m_d);
	m_d->pos++;
	ft_printf("Steps : +%d\n", m_d->pos);
}

void	down(t_map_data *m_d)
{
	m_d->map[m_d->player_y + 1][m_d->player_x] = 'P';
	m_d->map[m_d->player_y][m_d->player_x] = '0';
	m_d->player_y++;
	print_map(m_d);
	m_d->pos++;
	ft_printf("Steps : +%d\n", m_d->pos);
}

void	left(t_map_data *m_d)
{
	m_d->map[m_d->player_y][m_d->player_x - 1] = 'P';
	m_d->map[m_d->player_y][m_d->player_x] = '0';
	m_d->player_x--;
	print_map(m_d);
	m_d->pos++;
	ft_printf("Steps : +%d\n", m_d->pos);
}

void	right(t_map_data *m_d)
{
	m_d->map[m_d->player_y][m_d->player_x + 1] = 'P';
	m_d->map[m_d->player_y][m_d->player_x] = '0';
	m_d->player_x++;
	print_map(m_d);
	m_d->pos++;
	ft_printf("Steps : +%d\n", m_d->pos);
}

void	congrats(void)
{	
	ft_printf("\033[48;2;255;255;0m");
	ft_printf("\033[38;2;0;0;0m");
	ft_printf("\033[1m");
	ft_printf("MISSION PASSED ! ");
	ft_printf("\033[0m\n");
	ft_printf("\033[48;2;255;255;255m");
	ft_printf("\033[38;2;0;0;0m");
	ft_printf("\033[1m");
	ft_printf("\033[4m");
	ft_printf("RESPECT+ ");
	ft_printf("\033[0m\n");
}
