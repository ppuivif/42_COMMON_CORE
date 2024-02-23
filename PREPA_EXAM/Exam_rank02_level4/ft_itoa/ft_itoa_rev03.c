#include <stdlib.h>

int nb_digit(int nb)
{
	int len = 1;

	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 9)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char *result;
	int len = nb_digit(nbr);
	
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (nbr == 0)
		result[0] = '0';
	if (nbr < 0)
	{
		nbr *= -1;
		result[0] = '-';
	}
	result[len] = 0;
	while (nbr > 0)
	{
		result[len - 1] = nbr % 10 + 48;
		nbr /= 10;
		len --;
	}
	return (result);
}

#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc == 2)
		printf("%s\n", ft_itoa(atoi(argv[1])));
	return (0);
}

/*int main()
{
	int nbr = -145;
	printf("%d", nb_digit(nbr));
}*/