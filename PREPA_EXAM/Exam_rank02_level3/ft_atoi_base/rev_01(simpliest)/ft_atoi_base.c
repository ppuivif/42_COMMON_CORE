int convert(char c, int base)
{
	int nb = -1;

	if (c >= 'A' && c <= 'F')
		nb = c - 65 + 10;
	if (c >= 'a' && c <= 'f') 
		nb = c - 97 + 10;
	if (c >= '0' && c <= '9') 
		nb = c - 48;
	if (nb >= 0 && nb <= 15 && nb < base)
		return (nb);
	else
		return (-1);	
}


int	ft_atoi_base(const char *str, int base)
{
	int i = 0;
	int sign = 1;
	int nb = 0;

	if (!str || base <= 0 || base > 16)
		return (-1);
	while (str[i] && (str[i] == 32 || (str[i] >= 8 && str[i] <= 13)))
		i++;
	while (str[i] && (str[i] == 45 || str[i] == 43))
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while (convert(str[i], base) >= 0)
	{
		nb = nb * base + convert(str[i], base);
		i++;
	}
	return (nb * sign);
}

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int nbr = 0;

	if (argc == 3)
	{
		nbr = ft_atoi_base(argv[1], atoi(argv[2]));
		printf("%d\n", nbr);
	}
	return(0);
}