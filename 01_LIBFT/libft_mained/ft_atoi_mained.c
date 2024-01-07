/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_mained.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:41:24 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/14 17:16:57 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("real_function :\t%d\n", atoi(argv[1]));
	if (argc == 3)
		printf("ft_function :\t%d\n", ft_atoi(argv[1]));
}
