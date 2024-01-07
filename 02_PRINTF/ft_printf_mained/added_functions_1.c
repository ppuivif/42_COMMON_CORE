/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   added_functions_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:29:45 by ppuivif           #+#    #+#             */
/*   Updated: 2023/12/08 11:53:28 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
		i += ft_putchar(s[i]);
	return (i);
}

int	ft_pointer(unsigned long n)
{
	int		i;
	char	*tab;

	i = 0;
	tab = "0123456789abcdef";
	if (!n)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	if (n >= 16)
		i = ft_pointer(n / 16);
	if (i == 0)
		i = write (1, "0x", 2);
	write (1, &tab[n % 16], 1);
	i += 1;
	return (i);
}

int	ft_putnbr(int nb)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
		sign = 1;
	}
	if (nb > 9)
	{
		i = ft_putnbr(nb / 10);
	}
	i += ft_putchar((nb % 10) + '0');
	return (i + sign);
}

int	ft_putnbr_dec(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb > 9)
		i = ft_putnbr(nb / 10);
	i += ft_putchar((nb % 10) + '0');
	return (i);
}
