/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_and_sort_arrays_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:18:21 by ppuivif           #+#    #+#             */
/*   Updated: 2024/03/28 11:30:38 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		sign = (str[i++] == 45) * -2 + 1;
	if (str[i] == 0)
		return (-1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	if ((nb * sign) < INT_MIN || (nb * sign) > INT_MAX)
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

int	*build_int_arr(char **str_arr, int count)
{
	int	*int_arr;
	int	nb;
	int	i;

	int_arr = malloc(count * sizeof(int));
	if (!int_arr)
	{
		free_tab(str_arr);
		ft_putstr_fd("Error\nAllocation for int_array failed\n", 2);
		exit (EXIT_FAILURE);
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
