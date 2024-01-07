/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii_mained.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:24:41 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/09 09:37:39 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if ((c >= 0) & (c <= 127))
		return (1);
	return (0);
}

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("real_function return :\t%d\n", isascii(atoi(argv[1])));
	if (argc == 3)
		printf("ft_function return :\t%d\n", ft_isascii(atoi(argv[1])));
	return (0);
}
