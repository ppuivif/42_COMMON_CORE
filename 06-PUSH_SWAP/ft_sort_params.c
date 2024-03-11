/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:57:29 by ppuivif           #+#    #+#             */
/*   Updated: 2024/03/11 20:20:38 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	*ft_sort(int *arr, int count)
{
	int	*new_arr;
	int	i;
	int	hits;

	new_arr = malloc(count * sizeof(int));
	if (!new_arr)
	{
		ft_putstr_fd("Error\nArray new_arr couldn't be created\n", 2);
		exit (EXIT_FAILURE);
	}
	hits = 1;
	while (hits != 0)
	{
		i = 0;
		hits = 0;
		while (i < count)
		{
			if (arr[i] > arr[i + 1])
			{
				ft_swap_int(&arr[i], &arr[i + 1]);
				hits++;
			}
			if (arr[i] < arr[i + 1])
				new_arr[i] = arr[i + 1];
			i++;
		}
	}
	return (new_arr);
}
