/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint_mained.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:41:23 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/09 09:45:07 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if ((c >= 32) & (c <= 126))
		return (16384);
	return (0);
}

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("real_function return :\t%d\n", isprint(atoi(argv[1])));
	if (argc == 3)
		printf("ft_function return :\t%d\n", ft_isprint(atoi(argv[1])));
	return (0);
}
