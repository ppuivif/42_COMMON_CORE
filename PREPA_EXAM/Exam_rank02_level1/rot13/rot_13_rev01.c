#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1); 
}

void	rot13(char *str)
{
	int i = 0;
	char c;

	while (str && str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'm') || (str[i] >= 'A' && str[i] <= 'M'))
		{
			c = str[i] + 13;
			ft_putchar (c);
		}
		else if ((str[i] >= 'n' && str[i] <= 'z') || (str[i] >= 'N' && str[i] <= 'Z'))
		{
			c = str[i] - 13;
			ft_putchar (c);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}

int	main (int argc, char **argv)
{
	if (argc == 2)
		rot13(argv[1]);
	write (1, "\n", 1);
	return(0);
}
