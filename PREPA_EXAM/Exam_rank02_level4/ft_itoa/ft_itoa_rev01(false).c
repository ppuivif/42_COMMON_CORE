#include <limits.h>
#include <stdlib.h> 

char *ft_itoa(int nbr)
{
	char *str;
	int len = 0;
	int sign = 0;
	int i = 1;

	if (nbr < 0)
	{
		sign = 1;
		nbr *= -1;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		i++;
	}
	len = i + sign;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (sign == 1)
		str[0] = '-';
	if (nbr == 0)
		str[0] = 0;
	while (nbr > 0)
	{
		str[len - 1] = nbr % 10 + '0';
		nbr = nbr / 10;
		len--;
	}
	return (str);
}

#include <stdio.h>

int main ()
{
	int nbr = 10;
	printf("%s", ft_itoa(nbr));
	return (0);
}