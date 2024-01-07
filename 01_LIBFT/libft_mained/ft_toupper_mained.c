/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_mained.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:13:46 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/10 15:35:45 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	unsigned char	d;

	d = (unsigned char) c;
	if (d >= 97 && d <= 122)
		c = c - 32;
	else
		return (c);
	return (c);
}

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("real_function :\t%d\n", toupper(atoi(argv[1])));
	if (argc == 3)
		printf("ft_function :\t%d\n", ft_toupper(atoi(argv[1])));
	return (0);
}
