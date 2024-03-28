/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameters_in_arrays.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:11:22 by ppuivif           #+#    #+#             */
/*   Updated: 2024/03/28 16:52:39 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	if (count == 1)
	{
		free_tab(tab);
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	return (count);
}

void	check_parameters_are_integers(char **str_arr)
{
	int	i;

	i = 0;
	while (str_arr[i])
	{
		if (ft_atoi_long(str_arr[i]) == 1)
			i++;
		else if (ft_atoi_long(str_arr[i]) == 0)
		{
			free_tab(str_arr);
			ft_putstr_fd("Error\n", 2);
			exit (EXIT_FAILURE);
		}
		else if (ft_atoi_long(str_arr[i]) == -1)
		{
			free_tab(str_arr);
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
	}
}

void	check_no_duplicate(int *int_arr, int count, char **str_arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = 1;
		while (i + j < count)
		{
			if (int_arr[i] == int_arr[i + j])
			{
				free_arr(str_arr, int_arr);
				ft_putstr_fd("Error\n", 2);
				exit (EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	check_if_sorted(int *int_arr, int count, char **str_arr)
{
	int	i;

	i = 0;
	while (i < count - 1)
	{
		if (int_arr[i] < int_arr[i + 1])
			i++;
		else
			return ;
	}
	free_arr(str_arr, int_arr);
	exit (EXIT_FAILURE);
}
