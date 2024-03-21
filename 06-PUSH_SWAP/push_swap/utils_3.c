#include "push_swap.h"

void	print_tab_str(char **str_arr)
{
	int	i;

	i = 0;
	while (str_arr && str_arr[i])
	{
		ft_putstr_fd(str_arr[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	ft_putstr_fd("\n", 1);
}

void	print_tab_int(int *int_arr, int count)
{
	int	i;

	i = 0;
	while (int_arr && i < count)
	{
		ft_putnbr_fd(int_arr[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	ft_putstr_fd("\n", 1);
}
