/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mained.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:15:48 by ppuivif           #+#    #+#             */
/*   Updated: 2023/12/08 11:55:46 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	format(char c, va_list list)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar(va_arg(list, int));
	else if (c == 's')
		len = ft_putstr(va_arg(list, char *));
	else if (c == 'p')
		len = ft_pointer(va_arg(list, unsigned long));
	else if (c == 'd' || c == 'i')
		len = ft_putnbr(va_arg(list, int));
	else if (c == 'u')
		len = ft_putnbr_dec(va_arg(list, unsigned int));
	else if (c == 'x')
		len = ft_hexa_lower(va_arg(list, unsigned int));
	else if (c == 'X')
		len = ft_hexa_upper(va_arg(list, unsigned int));
	else if (c == '%')
		len = write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	list;

	i = 0;
	len = 0;
	va_start(list, str);
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += format(str[i + 1], list);
			i++;
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(list);
	return (len);
}

#include <stdio.h>
#include <limits.h>

int	main()
{
	char *s;
	s = "deux";
	printf("real_function give : %s\n", s);
	printf("real_function return : %d\n", printf("%s", s));
	ft_printf("ft_function give : %s\n", s);
	ft_printf("ft_function return : %d\n", ft_printf("%s", s));
}
