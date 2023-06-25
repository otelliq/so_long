/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:24:43 by otelliq           #+#    #+#             */
/*   Updated: 2023/01/31 02:46:58 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	i++;
	return (i);
}

char	*ft_strchr(char *str, char c)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)str;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return (&s[i + 1]);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		str1;
	int		str2;
	int		i;
	char	*res;

	i = 0;
	str1 = ft_strlen(s1);
	str2 = ft_strlen(s2);
	res = malloc(str1 + str2 + 1);
	if (!res)
		return (NULL);
	while (s1 && i < str1)
	{
		res[i] = s1[i];
		i++;
	}	
	i = 0;
	while (i < str2)
	{
		res[str1 + i] = s2[i];
		i++;
	}
	res[str1 + str2] = '\0';
	free (s1);
	return (res);
}
