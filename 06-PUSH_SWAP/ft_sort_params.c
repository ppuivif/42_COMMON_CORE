/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:57:29 by ppuivif           #+#    #+#             */
/*   Updated: 2024/02/26 20:59:10 by ppuivif          ###   ########.fr       */
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

int	*ft_sort(int *tab, int count)
{
	int *new_tab;
	int i;
	int hits;

	new_tab = malloc(count * sizeof(int));
	if (!new_tab)
	{
		ft_putstr_fd("Error\nArray new_tab couldn't be created\n", 2);
		exit (EXIT_FAILURE);
	}
	hits = 1;
	while (hits != 0)
	{	
		i = 0;
		hits = 0;
		while (i < count - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap_int(&tab[i], &tab[i + 1]);
				hits++;
			}
			if (tab[i] < tab[i + 1])
				new_tab[i] = tab[i + 1];
			i++;
		}
	}
	return(new_tab);
}
