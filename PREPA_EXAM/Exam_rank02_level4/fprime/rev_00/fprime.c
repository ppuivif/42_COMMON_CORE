#include <stdio.h>
#include <stdlib.h>

int	is_prime(unsigned int nb)
{
	unsigned int i = 2;

	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	fprime(unsigned int nbr)
{
	unsigned int nb = 2;

	if (nbr == 1)
		printf("1");
	while (nb <= nbr)
	{
		if (is_prime(nb) == 1 && nbr % nb == 0)
		{
			if (nbr / nb == 1)
				printf("%d", nb);
			else
				printf("%d*", nb);
			nbr = nbr / nb;
			nb = 2;
		}
		else
			nb++;
	}
}

int main (int argc, char **argv)
{
	if (argc == 2)
		fprime(atoi(argv[1]));
	printf("\n");
	return (0);
}