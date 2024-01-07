/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mained_rev6.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 10:14:02 by ppuivif           #+#    #+#             */
/*   Updated: 2023/12/17 12:06:51 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;

	len = ft_strlen(s);
	printf("%d\n", len);
	if (!s)
	{
		write(1, "(NULL)", 6);
		return (6);
	}
	else
		write(1, &s[1], len);
	return (len);
}

int	ft_put_hexa_lower(int nb)
{
	int	len;
	char	*tab;
	
	len = 0;
	tab = "0123456789abcdef";
	if (nb >= 16)
		len += ft_put_hexa_lower(nb / 16);
	len += write(1, &tab[nb % 16], 1);
	return (len);
}

int	main()
{
	int s = 9566;
//	int t;

	ft_put_hexa_lower(s);
//	printf("%d\n", t);
	return (0);
}
