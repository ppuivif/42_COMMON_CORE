#include "libftprintf.h"

int	format(char c, va_list list)
{
	int len;
	
	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(list, char));
	if (c == 's')
		len += ft_putstr(va_arg(list, char*));


}


int	printf(const char *str, ...)
{
	int len;
	int i;

	len = 0;
	i = 0;
	va_list list;

	if(!str)
		return (-1);
	va_start (list, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			len += format(str[i + 1], list);
			i++;
		}
		else
			len += write (1; &str[i], 1);
		i++;
	}
	va_end(list);
	return (len);

}
