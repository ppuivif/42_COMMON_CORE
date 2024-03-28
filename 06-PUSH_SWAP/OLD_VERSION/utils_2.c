#include "push_swap.h"

void	free_tab(char **arr)
{
	int	i;

	i = 0;
	while ((arr)[i])
	{
		free(arr[i]);
		i++;
	}
	if (arr)
		free(arr);
	arr = NULL;
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
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}
//		sign = (str[i++] == 45) * -2 + 1;//to replace previous code
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

int	*build_arr(char **str_arr, int count)
{
	int	*int_arr;
	int	nb;
	int	i;

	int_arr = malloc(count * sizeof(int));
	if (!int_arr)
	{
		free_tab(str_arr);
		return (NULL);// correct ?
	}
	nb = 0;
	i = 0;
	while (str_arr[i])
	{
		nb = ft_atoi(str_arr[i]);
		int_arr[i] = nb;
		i++;
	}
	return (int_arr);
}
