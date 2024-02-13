#include <unistd.h>

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}


void	rev_print(char *str)
{
	int i = (int)ft_strlen(str) - 1;

	while (i >= 0)
	{
		write (1, &str[i], 1);
		i--;
	}
}

int	main (int argc, char **argv)
{
	if (argc == 2)
		rev_print(argv[1]);
	write(1, "\n", 1);
	return(0);
}