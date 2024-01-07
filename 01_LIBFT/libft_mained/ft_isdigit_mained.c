/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_mained.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:28:40 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/03 18:09:16 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if ((c >= '0') & (c <= '9'))
		return (2048);
	return (0);
}

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("real_function return :\t%d\n", isdigit(atoi(argv[1])));
	if (argc == 3)
		printf("ft_function return :\t%d\n", ft_isdigit(atoi(argv[1])));
	return (0);
}
