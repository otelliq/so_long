/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 23:07:33 by otelliq           #+#    #+#             */
/*   Updated: 2023/04/20 03:19:16 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render(t_map_data *m_d)
{
	m_d->mlx = mlx_init();
	m_d->win = mlx_new_window(m_d->mlx, m_d->col_count * 50,
			m_d->row_count * 50, "so_long");
	m_d->wall = mlx_xpm_file_to_image(m_d->mlx,
			"./textures/1.xpm", &m_d->img_w, &m_d->img_h);
	m_d->road = mlx_xpm_file_to_image(m_d->mlx,
			"./textures/0.xpm", &m_d->img_w, &m_d->img_h);
	m_d->player = mlx_xpm_file_to_image(m_d->mlx,
			"./textures/P.xpm", &m_d->img_w, &m_d->img_h);
	m_d->coin = mlx_xpm_file_to_image(m_d->mlx,
			"./textures/C.xpm", &m_d->img_w, &m_d->img_h);
	m_d->exit = mlx_xpm_file_to_image(m_d->mlx,
			"./textures/E.xpm", &m_d->img_w, &m_d->img_h);
	print_map(m_d);
	mlx_hook(m_d->win, 2, 0, mouvements_p, m_d);
	mlx_hook(m_d->win, 17, 0, exittttt, m_d);
	mlx_loop(m_d->mlx);
}

void	printer(t_map_data *m_d, int i, int j, char map)
{
	if (map == 'P')
		mlx_put_image_to_window(m_d->mlx, m_d->win,
			m_d->player, i * 50, j * 50);
	if (map == '1')
		mlx_put_image_to_window(m_d->mlx, m_d->win,
			m_d->wall, i * 50, j * 50);
	if (map == 'C')
		mlx_put_image_to_window(m_d->mlx, m_d->win,
			m_d->coin, i * 50, j * 50);
	if (map == 'E')
		mlx_put_image_to_window(m_d->mlx, m_d->win,
			m_d->exit, i * 50, j * 50);
}

void	print_map(t_map_data *m_d)
{
	char	map;
	int		i;
	int		j;

	i = 0;
	while (i < m_d->col_count)
	{
		j = 0;
		while (j < m_d->row_count)
		{
			map = m_d->map[j][i];
			mlx_put_image_to_window(m_d->mlx, m_d->win,
				m_d->road, i * 50, j * 50);
			printer(m_d, i, j, map);
			j++;
		}
		i++;
	}
}

int	mouvements_p(int keycode, t_map_data *m_d)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 13)
	{
		move_up(m_d);
	}
	else if (keycode == 0)
	{
		move_left(m_d);
	}
	else if (keycode == 1)
	{
		move_down(m_d);
	}
	else if (keycode == 2)
	{
		move_right(m_d);
	}
	return (0);
}
