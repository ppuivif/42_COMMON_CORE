#include "push_swap.h"

int	count_parameters(char **tab)
{
	int	count;

	count = 0;
	while (tab[count])
		count++;
	if (count == 0)
	{
		free_tab(tab);
		ft_putstr_fd("Error\nThere isn't any number in the arguments " \
			"given in the command line\n", 1);
		exit(EXIT_FAILURE);
	}	if (count == 1)
	{
		free_tab(tab);
		ft_putstr_fd("Error\nThere isn't enough number in the arguments " \
			"given in the command line\n", 1);
		exit(EXIT_FAILURE);
	}
	return (count);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while ((tab)[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
	tab = NULL;
}

int	ft_atoi_long(char *str)
{
	int			i;
	int			sign;
	long int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	if (str[i] == 0)
		return (-1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	if ((nb * sign) <= INT_MIN || (nb * sign) >= INT_MAX)
		return (0);
	return (1);
}

void	print_tab_str(char **tab_str)
{
	int	i;

	i = 0;
	while (tab_str && tab_str[i])
	{
		ft_putstr_fd(tab_str[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}

void	print_tab_int(int *tab_int, int count)
{
	int	i;

	i = 0;
	while (tab_int && i < count)
	{
		ft_putnbr_fd(tab_int[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}

char	*ft_strjoin_freed(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof (char));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (str);
}
