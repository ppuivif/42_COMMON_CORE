#include <limits.h>
#include <unistd.h>

void	putnbr(int nbr)
{
	char c;

/*	if (nbr == INT_MIN)
		write(1, "-2147483648", 11);
	if (nbr < 0)
	{
		write (1, "-", 1);
		nbr *= -1;
	}*/
	if (nbr > 9)
		putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
	(void)argv;
	int i = argc - 1;
	putnbr(i);
	write(1, "\n", 1);
	return (0);
}