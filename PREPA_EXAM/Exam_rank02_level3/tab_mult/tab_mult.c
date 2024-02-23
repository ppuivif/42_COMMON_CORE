#include <unistd.h>

int	ft_atoi(char *str)
{
	int i = 0;
	int	nb = 0;

	while (str && str[i])
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb);
}

void	ft_putnbr(int nb)
{
	char result;
	
	if(nb == -2147483647)
		write(1, "-2147483647", 11);
	else
	{
		if (nb > 9)
			ft_putnbr(nb / 10);
		result = nb % 10 + '0';
		write (1, &result, 1);
	}
}

void	tab_mult(int nb)
{
	int i = 1;
	int result = 0;

	while (i < 10)
	{
		result = i * nb;
		ft_putnbr(i);
		write(1, " x ", 3);
		ft_putnbr(nb);
		write(1, " = ", 3);
		ft_putnbr(result);
		write(1, "\n", 1);
		i++;
	}
}

int main (int argc, char **argv)
{
	if (argc == 2)
		tab_mult(ft_atoi(argv[1]));
	else
		write(1, "\n", 1);
	return (0);
}

/*int main (int argc, char **argv)
{
	if (argc == 2)
		ft_putnbr(ft_atoi(argv[1]));
	else
		write(1, "\n", 1);
	return (0);
}*/