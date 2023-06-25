/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:33:29 by otelliq           #+#    #+#             */
/*   Updated: 2023/04/20 03:09:23 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_printf("Error, more or less arguments!");
		exit(0);
	}
	ft_so_long(av);
	return (0);
}

void	checker00(char **av, t_map_data *m_d)
{
	if (!ber_checker(av[1], ".ber"))
	{
		ft_printf("Error, wrong map name!");
		exit(0);
	}
	if (walls_checker(m_d) == 0)
	{
		ft_printf("Error , map is not surrounded by walls!");
		exit(0);
	}
	if (rectangle_check(m_d) == 0)
	{
		ft_printf("Error , map is not rectangular!");
		exit(0);
	}
	if (collectible_checker(m_d) == 0)
	{
		ft_printf("Error , no collectibles found!");
		exit(0);
	}
}

void	checker01(char **av, t_map_data *m_d)
{
	if (player_checker(m_d) == 0)
	{
		ft_printf("Error , more or less than one player found!");
		exit(0);
	}
	if (exit_checker(m_d) == 0)
	{
		ft_printf("Error , more or less than one exit found!");
		exit(0);
	}
	path_checker(m_d->map1, m_d->player_x, m_d->player_y);
	if (path_checker_result(m_d) == 0)
	{
		ft_printf("Error , invalid path!");
		exit(0);
	}
}

void	ft_so_long(char **av)
{
	int			i;
	int			j;
	int			fd;
	char		*line;
	t_map_data	*m_d;

	m_d = malloc(sizeof (t_map_data));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit(1);
	line = get_next_line(fd);
	if (line == NULL)
		exit(1);
	m_d->pos = 0;
	m_d->row_count = line_counter(av);
	m_d->col_count = column_counter(line);
	check_newlines(av);
	copie_1(m_d, av[1]);
	copie_2(m_d, av[1]);
	checker00(av, m_d);
	checker01(av, m_d);
	components_check(m_d);
	render(m_d);
}
