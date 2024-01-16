/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:04:06 by ppuivif           #+#    #+#             */
/*   Updated: 2024/01/10 10:47:28 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int i;
	unsigned int j;
	
	i = 1;
	j = 1;
	if (a == 0 || b == 0)
		return (0);
	while ((a * i) <= (b * j))
	{
		while ((a * i) <= (b * j))
		{
			if (a * i == b * j)
				return (b * j);
			i++;
		}
		j++;
	}
	return (a * i);
}

#include <stdio.h>

int	main()
{
	unsigned int a = 5;
	unsigned int b = 10;

	printf("%d", lcm(a, b));
	return (0);	
}