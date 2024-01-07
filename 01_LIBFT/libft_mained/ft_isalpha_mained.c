/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_mained.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:38:58 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/03 18:00:50 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (((c >= 'a') & (c <= 'z')) || ((c >= 'A') & (c <= 'Z')))
		return (1024);
	return (0);
}

#include <ctype.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("real_function return :\t%d\n", isalpha(atoi(argv[1])));
	if (argc == 3)
		printf("ft_function return :\t%d\n", ft_isalpha(atoi(argv[1])));
	return (0);
}
