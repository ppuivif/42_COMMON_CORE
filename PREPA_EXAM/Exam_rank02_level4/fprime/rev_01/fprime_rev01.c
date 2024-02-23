#include <stdio.h>
#include <stdlib.h>

int		is_prime(int nb)
{
	int i = nb / 2;

	while (i > 1)
	{
		if ((nb % i) != 0)
			i--;
		else
			return (0);
	}
	return (1);
}

void	fprime(int nb)
{
	int i = 2;

	if (nb == 1)
		printf("1");
	while (i <= nb)
	{
		if ((nb % i == 0) && (is_prime(i) == 1))
		{
			if (nb / i == 1)
				printf("%d", i);
			else
				printf("%d*", i);
			nb = nb / i;
			i = 2;
		}
		else
			i++;
	}
}



int	main(int argc, char **argv)
{
	if(argc == 2 && atoi(argv[1]) > 0)
		fprime(atoi(argv[1]));
	printf("\n");
	return(0);
}