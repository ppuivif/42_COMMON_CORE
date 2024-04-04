#include "libftprintf.h"

#include <limits.h>

int	ft_putstr(char *str)
{
	int i = 0;
	
	if (!str)
	{	
		write (1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_base(int nb, int base)
{
	int len = 0;
	char c;
	char *tab = "0123456789abcdef";

	if (nb == INT_MIN)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{	
		nb *= -1;
		len += write(1, "-", 1);
	}	
	if (nb >= base)
		len += ft_putnbr_base(nb / base, base);
	c = tab[nb % base];
	len += write(1, &c, 1);
	return (len);
}


int	ft_lower_hexa(unsigned int nb, unsigned int base)
{
	int len = 0;
	char c;
	char *tab = "0123456789abcdef";

	if (nb >= base)
		len += ft_putnbr_base(nb / base, base);
	c = tab[nb % base];
	len += write(1, &c, 1);
	return (len);
}

static int	format(char c, va_list list)
{
	int len = 0;

	if (c == 's')
		len += ft_putstr(va_arg(list, char *));
	if (c == 'd')
		len += ft_putnbr_base(va_arg(list, int), 10);
	if (c == 'x')
		len += ft_lower_hexa(va_arg(list, unsigned int), 16);
	if (c == '%')
		len += write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int i = 0;
	int len = 0;
	va_list list;
	
	if (!str)
		return (-1);
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			len += format(str[i + 1], list);
			i++;
		}
		else
			len += write (1, &str[i], 1);
		i++;
	}
	va_end(list);
	return (len);
}


