/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:38:49 by ppuivif           #+#    #+#             */
/*   Updated: 2023/12/18 19:23:28 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	add_prime_sum(unsigned int nb)
{
	unsigned int	i = 2;
	unsigned int	j = 2;
	int	result = 1;

	while (i <= nb)
	{
		while (j <= i);
		{
			if (i % j != 0)
				j++;
			else
			{
				result += i;
				break;
			}
		}
		i++;
	}
	printf("%d", result);
//	write (1, &result, 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2 && atoi(argv[1]) > 0)
		add_prime_sum(atoi(argv[1]));
	else
		write (1, "0", 1);
	write (1, "\n", 1);
	return (0);
}
