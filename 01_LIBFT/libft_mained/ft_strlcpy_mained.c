/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_mained.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:33:31 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/10 11:43:25 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = ft_strlen(src);
	if (size == 0)
		return (n);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (n);
}

#include <bsd/string.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		printf("real_function :\n");
		printf("\tsource :\t%s\n", argv[3]);
		printf("\tdestination :\t%s\n", argv[2]);
		strlcpy(argv[2], argv[3], atoi(argv[1]));
		printf("\tdestination after function :\t%s\n", argv[2]);
		printf("\tfunction_return :\t%ld\n",
			strlcpy(argv[2], argv[3], atoi(argv[1])));
	}
	if (argc == 5)
	{
		printf("ft_function :\n");
		printf("\tsource :\t%s\n", argv[3]);
		printf("\tdestination :\t%s\n", argv[2]);
		ft_strlcpy(argv[2], argv[3], atoi(argv[1]));
		printf("\tdestination after function :\t%s\n", argv[2]);
		printf("\tfunction_return :\t%ld\n",
			ft_strlcpy(argv[2], argv[3], atoi(argv[1])));
	}
	return (0);
}
