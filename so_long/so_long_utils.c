/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 04:55:32 by otelliq           #+#    #+#             */
/*   Updated: 2023/04/20 02:59:42 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ber_checker(char *haystack, char *needle)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (needle[j] == '\0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	exittttt(void)
{
	exit(0);
}

void	image_error(t_map_data *m_d)
{
	if ((m_d->wall == NULL) || (m_d->road == NULL) || (m_d->coin == NULL)
		|| (m_d->player == NULL) || (m_d->exit == NULL))
		ft_printf("error");
	exit(1);
}

void	components_check(t_map_data *m_d)
{
	int	i;
	int	j;

	i = 0;
	while (i < m_d->row_count)
	{
		j = 0;
		while (j < m_d->col_count)
		{
			if (m_d->map[i][j] != '1' && m_d->map[i][j] != '0'
			&& m_d->map[i][j] != 'P' && m_d->map[i][j] != 'C'
			&& m_d->map[i][j] != 'E')
			{
				ft_printf("Error, invalid character in the map!");
				exit(1);
			}
				j++;
		}
		i++;
	}
}
