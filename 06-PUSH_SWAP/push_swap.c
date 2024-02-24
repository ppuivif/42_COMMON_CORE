#include "push_swap.h"

int	count_parameters(char **tab)
{
	int	count;

	count = 0;
	while (tab[count])
	{
		printf("%s\n", tab[count]);
		count++;
	}
	if (count == 0 || count == 1)
	{
		ft_putstr_fd("Error\nThere isn't enough number in the arguments " \
			"given in the command line\n", 1);
		exit(EXIT_FAILURE);
	}
	return (count);
}

void	check_parameters(tab)
{


	
}


int	main(int argc, char **argv)
{
	char	**tab;
	int 	count;

	count = 0;
	if (argc < 2)
		exit(EXIT_FAILURE);
	if (argc > 2)
	{
		ft_putstr_fd("Error\nThere are to many arguments " \
			"in the command line\n", 1);
		exit(EXIT_FAILURE);
	}
	tab = ft_split(argv[1], ' ');
	count = count_parameters(tab);
	printf("%d\n", count);
	check_parameters(tab);

}
