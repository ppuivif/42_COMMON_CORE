#include "push_swap.h"

void	check_parameters_are_integers(char **tab_str)
{
	int i;

	i = 0;
	while(tab_str[i])
	{
		if (ft_atoi_long(tab_str[i]) == 1)
			i++;
		else if (ft_atoi_long(tab_str[i]) == 0)
		{	
			free_tab(tab_str);
			ft_putstr_fd("Error\nAt least one parameter " \
				"is out of range of integers\n", 2);
			exit (EXIT_FAILURE);
		}		
		else if (ft_atoi_long(tab_str[i]) == -1)
		{
			free_tab(tab_str);
			ft_putstr_fd("Error\nAt leat one parameter " \
				"isn't an integer\n", 2);
			exit(EXIT_FAILURE);
		}
	}
}
	
int	*build_tab(char **tab_str, int count)
{
	int *tab_int;
	int nb;
	int i;
	
	tab_int = malloc(count * sizeof(int));
	if (!tab_int)
	{
		free_tab(tab_str);
		return (NULL);// correct ?
	}
	nb = 0;
	i = 0;
	while(tab_str[i])
	{
		nb = ft_atoi(tab_str[i]);
		tab_int[i] = nb;
		i++;
	}
	return (tab_int);
}

int	main(int argc, char **argv)
{
	char	*str;
	char	**tab_str;
	int 	count;
	int 	*tab_int;
	int		*sort_tab;
	int		i;

	count = 0;
	i = 2;
	if (argc < 2)
	{
		ft_putstr_fd("Error\nArguments are missing " \
			"in the command line\n", 2);
		exit(EXIT_FAILURE);
	}
	str = ft_strjoin(argv[1], " ");
	while (argv[i])
	{
		str = ft_strjoin_freed(str, argv[i]);
		str = ft_strjoin_freed(str, " ");
		i++;
	}
	tab_str = ft_split(str, ' ');
	free(str);
	count = count_parameters(tab_str);
	printf("count : %d\n", count);
	ft_putstr_fd("\n", 1);
	check_parameters_are_integers(tab_str);
	print_tab_str(tab_str);
	tab_int = build_tab(tab_str, count);
	check_no_duplicate(tab_int, count);
	print_tab_int(tab_int, count);
	sort_tab = ft_sort(tab_int, count);
	print_tab_int(tab_int, count);
	free_tab(tab_str);
	free(tab_int);
}
