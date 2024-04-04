#include "libftprintf.h" 
#include <stdio.h>

int	main()
{
//	char *s;
//	s = "deux";

	int d;
	d = -1;

//	printf("real_function give : %s\n", s);
//	printf("real_function return : %d\n", printf("%s\n", s));
//	printf("real_function return : %d\n", printf("%d\n", d));
	printf("real_function return : %d\n", printf("%x\n", d));
//	ft_printf("ft_function give : %s\n", s);
//	ft_printf("ft_function return : %d\n", ft_printf("%s\n", s));
//	ft_printf("ft_function return : %d\n", ft_printf("%d\n", d));
	ft_printf("ft_function return : %d\n", ft_printf("%x\n", d));
}
