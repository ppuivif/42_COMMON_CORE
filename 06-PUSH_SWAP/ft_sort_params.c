/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:57:29 by ppuivif           #+#    #+#             */
/*   Updated: 2024/02/28 08:19:11 by ppuivif          ###   ########.fr       */
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

	new_arr = malloc(count * sizeof(t_element));
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
		while (i < count - 1)
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
