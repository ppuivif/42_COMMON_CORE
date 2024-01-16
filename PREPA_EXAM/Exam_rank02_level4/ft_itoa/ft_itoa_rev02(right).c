#include <stdlib.h>

int	nb_digit(int nbr)
{
	int i = 0;

	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int ft_sign(int *nbr)
{
	int sign = 0;

	if (*nbr < 0)
	{
		sign = 1;
		*nbr *= -1; 
	}
	return (sign);
}

char	*ft_itoa(int nbr)
{
	char *str;
	int sign;

	int i;

	sign = ft_sign(&nbr);
	i = nb_digit(nbr) + sign;
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[i] = 0;
	if (nbr == 0)
		str[0] = '0';
	while (nbr > 0)
	{
		str[i - 1] = nbr % 10 + '0';
		nbr /= 10;
		i--;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}

#include <stdio.h>
int main()
{
	printf("%s", ft_itoa(-452));
}