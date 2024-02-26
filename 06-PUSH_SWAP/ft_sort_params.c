/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:57:29 by ppuivif           #+#    #+#             */
/*   Updated: 2024/02/25 20:27:22 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	*ft_sort(int *tab, int count)
{
	int *new_tab;
	int i;
	int hits;

	new_tab = malloc(count * sizeof(int));
	if (!new_tab)
		exit (EXIT_FAILURE);
	while (hits > count)
	{	
		i = 0;
		while (i < count - 1)
		{
			if (tab[i] > tab[i + 1])
				ft_swap(tab[i], tab[i + 1]);
			if (tab[i] < tab[i + 1])
			{
				new_tab[i] = tab[i + 1];
				hits++;
			}
			i++;
		}
	}
}
