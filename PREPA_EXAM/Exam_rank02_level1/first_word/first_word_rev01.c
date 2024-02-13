#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	first_word(char *str)
{
	int i = 0;

	while (str[i] && (str[i] == 32 || str[i] == '\t'))
		i++;
	while (str[i] && str[i] != 32 && str[i] != '\t')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		first_word(argv[1]);
	ft_putchar ('\n');
	return (0);
}