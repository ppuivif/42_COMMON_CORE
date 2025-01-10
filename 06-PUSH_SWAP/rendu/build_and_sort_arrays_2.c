/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_and_sort_arrays_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:57:29 by ppuivif           #+#    #+#             */
/*   Updated: 2024/03/27 11:44:56 by ppuivif          ###   ########.fr       */
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

void	ft_sort_int_arr(int *arr, int count)
{
	int	i;
	int	hits;

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
			i++;
		}
	}
}
