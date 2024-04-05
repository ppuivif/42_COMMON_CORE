/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:41:24 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/14 17:15:53 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	j;
	int	nbr;

	i = 0;
	j = 1;
	nbr = 0;
	while (nptr[i] != '\0' && (nptr[i] == 32 || (nptr[i] > 8 && nptr[i] < 14)))
		i++;
	if (nptr[i] != '\0' && (nptr[i] == 45 || nptr[i] == 43))
	{
		if (nptr[i] == 45)
			j = j * -1;
		i++;
	}
	while (nptr[i] != '\0' && nptr[i] > 47 && nptr[i] < 58)
	{
		nbr = (nbr * 10) + (nptr[i] - 48);
		i++;
	}
	return (nbr * j);
}
