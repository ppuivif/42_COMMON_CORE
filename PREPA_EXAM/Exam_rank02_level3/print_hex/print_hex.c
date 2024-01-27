#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int i = 0;
	int sign = 1;
	int nbr = 0;

	while (str[i] && str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] && str[i] == 43 || str[i] == 45)
	{	
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		nbr = nbr * 10 + str[i] - 48;
		i++;
	}
	return (nbr * sign);
}


void	putnbr_base_16(int nbr)
{
	char *tab = "0123456789abcdef";
	char res;
	
	if (nbr > 15)
	{
		putnbr_base_16(nbr / 16);
	}
	nbr = nbr % 16;
	res = tab[nbr];
	write(1, &res, 1);
}



int main(int argc, char **argv)
{
	if (argc == 2)
		putnbr_base_16(ft_atoi(argv[1]));
	write(1, "\n", 1);
	return(0);
}
