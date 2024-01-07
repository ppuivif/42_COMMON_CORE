/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mained_rev.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 07:47:48 by ppuivif           #+#    #+#             */
/*   Updated: 2023/12/15 08:43:22 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

int	ft_putnbr(int i);

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
	{
		write(1, "(NULL)", 6);
		return (6);
	}
	while (str[len])
		len += ft_putchar(str[len]);
	return (len);
}



static int	ft_format(va_list list, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar(va_arg(list, int));
	if (c == 's')
		len = ft_putstr(va_arg(list, char *));
	if (c == 'd' || c == 'i')
		len = ft_putnbr(va_arg(list, int));
	return (len);


}

int	ft_printf(const char *s, ...)
{
	int	i;
	int	len;
	va_list	list;

	i = 0;
	len = 0;
	va_start(list, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			len += ft_format(list, s[i + 1]);
			i++;
		}
		else
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(list);
	return(len);
}

int	ft_putnbr(int	n)
{
	int	len;
	int	sign;

	len = 0;
	if (n == INT_MIN)
	{
		write(1, "2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		sign = 1;
		n *= -1;
		write(1, "-", 1);
	}
	else if (n > 9)
		len = ft_putnbr(n / 10);
	len += ft_putchar((n % 10) + '0');
	return(len + sign);
}



#include <stdio.h>

int	main()
{
	char	*s;

	s = "abcd";
	ft_printf("ft : %d\n", ft_printf("ft : %s", s)); 
	printf("re : %d\n", printf("re : %s", s));
	return (0);
}
