/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:25:01 by otelliq           #+#    #+#             */
/*   Updated: 2023/01/31 01:21:50 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9
# endif

char	*get_next_line(int fd);
char	*get_first_line(char *s);
char	*get_rest_line(char *s);
char	*ft_read_line(int fd, char *s);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, char c);
#endif
