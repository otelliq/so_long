/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:37:02 by otelliq           #+#    #+#             */
/*   Updated: 2023/04/19 07:42:19 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstrr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		ft_putstrr("(null)");
		return (6);
	}
	while (s[i])
	{
		ft_putcharr(s[i]);
		i++;
	}
	return (i);
}

int	counterunsi(long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_putunsignedd(unsigned int n)
{
	if (n >= 0 && n <= 9)
		ft_putcharr(n + 48);
	else
	{
		ft_putunsignedd(n / 10);
		ft_putunsignedd(n % 10);
	}
	return (counterunsi(n));
}

int	counter(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	else if (n == 0)
		i++;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_putnbrr(long int n)
{
	int	count;

	count = counter(n);
	if (n >= 0 && n <= 9)
		ft_putcharr(n + 48);
	else if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		ft_putnbrr(n);
	}
	else
	{
		ft_putnbrr(n / 10);
		ft_putnbrr(n % 10);
	}
	return (count);
}
