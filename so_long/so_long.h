/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:38:33 by otelliq           #+#    #+#             */
/*   Updated: 2023/04/20 03:10:12 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>

# define PLAYER 'P'
# define PATH '0'
# define WALL '1'
# define EXI 'E'
# define COLLECTIBLE 'C'

typedef struct s_map_data
{
	int		row_count;
	int		col_count;
	char	**map;
	char	**map1;
	int		player_x;
	int		player_y;
	void	*mlx;
	void	*win;
	void	*img;
	void	*wall;
	void	*road;
	void	*player;
	void	*coin;
	void	*exit;
	int		img_w;
	int		img_h;
	int		c;
	int		pos;
}t_map_data;

int		ber_checker(char *haystack, char *needle);
int		walls_checker(t_map_data *m_d);
int		rectangle_check(t_map_data *m_d);
int		collectible_checker(t_map_data *m_d);
int		player_checker(t_map_data *m_d);
int		exit_checker(t_map_data *m_d);
int		line_counter(char **av);
int		column_counter(char *line);
int		path_checker_result(t_map_data *m_d);
char	**map_clone(t_map_data *m_d, int fd);
void	path_checker(char **map, int x, int y);
void	copie_1(t_map_data *m_d, char *path);
void	copie_2(t_map_data *m_d, char *path);
void	render(t_map_data *m_d);
void	print_map(t_map_data *m_d);
void	image_error(t_map_data *m_d);
void	image_error(t_map_data *m_d);
int		mouvements_p(int keycode, t_map_data *m_d);
void	move_up(t_map_data *m_d);
void	move_down(t_map_data *m_d);
void	move_right(t_map_data *m_d);
void	move_left(t_map_data *m_d);
void	up(t_map_data *m_d);
void	down(t_map_data *m_d);
void	left(t_map_data *m_d);
void	right(t_map_data *m_d);
int		exittttt(void);
int		collectible_counter(t_map_data *m_d);
void	printer(t_map_data *m_d, int i, int j, char map);
void	checker00(char **av, t_map_data *m_d);
void	checker01(char **av, t_map_data *m_d);
void	ft_so_long(char **av);
void	components_check(t_map_data *m_d);
void	congrats(void);
void	new_line_detected(char *res);
void	check_newlines(char **av);
char	*ft_calloc(int count, int size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
#endif
