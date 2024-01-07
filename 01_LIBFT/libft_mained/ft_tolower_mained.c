/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower_mained.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:42:48 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/10 15:50:30 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	unsigned char	d;

	d = (unsigned char) c;
	if (d >= 65 && d <= 90)
		c = c + 32;
	else
		return (c);
	return (c);
}

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("real_function :\t%d\n", tolower(atoi(argv[1])));
	if (argc == 3)
		printf("ft_function :\t%d\n", ft_tolower(atoi(argv[1])));
	return (0);
}
