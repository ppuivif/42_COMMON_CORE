/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:32:30 by ppuivif           #+#    #+#             */
/*   Updated: 2024/02/12 09:57:58 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	fizzbuzz()
{
	int	nb;
	char	di;
	char	un;

	nb = 1;
	while (nb < 100)
	{
		if (nb % 15 == 0)
			write(1, "fizzbuzz", 8);
		else if (nb % 3 == 0)
			write(1, "fizz", 4);
		else if (nb % 5 == 0)
			write(1, "buzz", 4);
		else
		{
			di = (nb / 10) + '0';
			un = nb % 10 + '0';
			if (nb < 10)
				write(1, &un, 1);
			else
			{
				write(1, &di, 1);
				write(1, &un, 1);
			}
		}
		write(1, "\n", 1);
		nb++;
	
	}
	write(1, "buzz\n", 4);
}


int	main()
{
	fizzbuzz();
	return (0);
}
