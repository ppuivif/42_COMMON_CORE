#include <unistd.h>

void	ft_putnbr(int nbr)
{
	char nb;

	if (nbr > 9)
		ft_putnbr(nbr / 10);
	nb = nbr % 10 + '0';
	write (1, &nb, 1);
}

void	fizzbuzz()
{
	int i = nbr;

	while (nbr <= 100)
	{
		if (nbr % 15 == 0)
			write(1, "fizzbuzz", 9);
		else if (nbr % 3 == 0)
			write(1, "fizz", 5);
		else if (nbr % 5 == 0)
			write(1, "buzz", 5);
		else
			ft_putnbr(nbr);
		write (1, "\n", 1);
		i++;
	}
}


int	main()
{
	fizzbuzz();
	return(0);
}
