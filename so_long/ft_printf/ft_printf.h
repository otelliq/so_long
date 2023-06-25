/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:48:09 by otelliq           #+#    #+#             */
/*   Updated: 2022/11/25 11:35:41 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<unistd.h>
# include<stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_formatchooser(char str, va_list args);
int	ft_putcharr(char c);
int	ft_putnbrr(long int n);
int	ft_putstrr(char *s);
int	ft_putunsignedd(unsigned int n);
int	ft_puthexx(unsigned long int n, char *c);
#endif
