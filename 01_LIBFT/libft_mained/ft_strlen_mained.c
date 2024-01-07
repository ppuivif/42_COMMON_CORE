/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_mained.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:40:26 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/09 09:53:12 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	if (argc > 0)
	{
		printf("real_function\t%ld\n", strlen(argv[1]));
		printf("ft_function\t%ld\n", ft_strlen(argv[1]));
	}
	return (0);
}
