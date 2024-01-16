#include <limits.h>
#include <stdio.h>

int	ft_atoi(const char *str);

int main()
{
	printf("%d", ft_atoi("-2147483649"));
	//printf("%d", INT_MIN);
	return (0);
}