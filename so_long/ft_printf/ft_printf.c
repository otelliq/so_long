/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:07:57 by otelliq           #+#    #+#             */
/*   Updated: 2023/04/16 05:04:28 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	counthex(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	ft_puthexx(unsigned long n, char *c)
{
	if (n < 16)
		ft_putcharr(c[n]);
	else
	{
		ft_puthexx(n / 16, c);
		ft_puthexx(n % 16, c);
	}
	return (counthex(n));
}

int	ft_putcharr(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formatchooser(char str, va_list args)
{
	int	length;

	length = 0;
	if (str == 'd' || str == 'i')
		length += ft_putnbrr(va_arg(args, int));
	else if (str == 'c')
		length += ft_putcharr(va_arg(args, unsigned int));
	else if (str == 's')
		length += ft_putstrr(va_arg(args, char *));
	else if (str == 'p')
	{
		length += ft_putstrr("0x");
		length += ft_puthexx(va_arg(args, unsigned long int),
				"0123456789abcdef");
	}
	else if (str == 'u')
		length += ft_putunsignedd(va_arg(args, unsigned int));
	else if (str == 'x')
		length += ft_puthexx(va_arg(args, unsigned int), "0123456789abcdef");
	else if (str == 'X')
		length += ft_puthexx(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (str == '%')
		length += ft_putcharr('%');
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			length += ft_formatchooser(format[++i], args);
			i++;
		}
		else
			length += ft_putcharr(format[i++]);
	}
	va_end(args);
	return (length);
}
