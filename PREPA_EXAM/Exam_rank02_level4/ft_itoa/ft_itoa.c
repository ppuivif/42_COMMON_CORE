#include <stdlib.h>

int ft_sign(int nbr)
{
	int sign = 0;
	
	if (nbr < 0)
		sign = 1;
	return (sign);
}

int ft_len(long int nbr)
{
	int len = 0;

	if (nbr == 0)
		len = 1;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char *str;
	int sign;
	//int i = 0;
	int len = 0;

	sign = ft_sign(nbr);
	if (nbr < 0)
		nbr *= -1;
	len = ft_len(nbr) + sign;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr == 0)
		str[0] = '0';
	if (sign == 1)
		str[0] = '-';
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
	int nbr = -155;
	printf("%s", ft_itoa(nbr));
	return (0);
}