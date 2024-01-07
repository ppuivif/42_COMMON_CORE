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

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		write(1, "(NULL)", 6);
		return (6);
	}
	while (s[len])
	{	
		write(1, &s[len], 1);
		len++;
	}
	return (len);
}

int	ft_putnbr(int nb)
{
	int	len;
	int	sign;

	
	len = 0;
	sign = 0;
	if (nb == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		sign = 1;
		nb *= -1;
	}
	if (nb > 9)
		len += ft_putnbr(nb / 10);
	len += ft_putchar(nb % 10 + '0');
	return (len + sign); 
}

int	ft_pointer(unsigned long int ptr)
{
	int	len;
	char	*tab;
	
	len = 0;
	tab = "0123456789abcdef";
	
	if (ptr > 9)
		len = ft_pointer(ptr / 16);
	if (len == 0)
		len += write(1, "0x", 2);
	len += write(1, &tab[ptr % 16], 1);
	return (len); 
}	

int	ft_format(va_list list, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar(va_arg(list, int));
	if (c == 's')
		len = ft_putstr(va_arg(list, char *));
	if (c == 'd' || c == 'i')
		len = ft_putnbr(va_arg(list, int));
	if (c == 'p')
		len = ft_pointer(va_arg(list, unsigned long int));
	return (len);
}

int	ft_printf(char *s, ...)
{
	int	i;
	int	len;
	va_list list;


	i = 0;
	len = 0;
	va_start(list, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += ft_format(list, s[i + 1]);
			i++;
		}
		else
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(list);
	return (len);
}

#include <stdio.h>

int	main()
{
	char *s = "abcd";

	printf("re : %d", printf("re : %p", s));
	ft_printf("ft : %d", ft_printf("ft : %p", s));
	return (0);
}
