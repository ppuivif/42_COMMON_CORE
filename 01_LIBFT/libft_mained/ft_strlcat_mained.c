/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_mained.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:47:20 by ppuivif           #+#    #+#             */
/*   Updated: 2023/12/06 09:02:57 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	m;
	size_t	n;

	i = 0;
	m = ft_strlen(src);
	if (size == 0)
		return (m);
	n = ft_strlen(dst);
	if (n >= size)
		return (m + size);
	while (src[i] && (n + i) < size - 1)
	{
		dst[n + i] = src[i];
		i++;
	}
	dst[n + i] = '\0';
	return (n + m);
}

#include <bsd/string.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
/*	if (argc == 4)
	{
		printf("real_function :\n");
		printf("\tsource :\t%s\n", argv[3]);
		printf("\tdestination :\t%s\n", argv[2]);
		strlcat(argv[2], argv[3], atoi(argv[1]));
		printf("\tdestination after function :\t%s\n", argv[2]);
		printf("\tfunction_return :\t%ld\n",
			strlcat(argv[2], argv[3], atoi(argv[1])));
	}*/
	if (argc == 5)
	{
		printf("ft_function :\n");
		printf("\tsource :\t%s\n", argv[3]);
		printf("\tdestination :\t%s\n", argv[2]);
		ft_strlcat(argv[2], argv[3], atoi(argv[1]));
		printf("\tdestination after function :\t%s\n", argv[2]);
		printf("\tfunction_return :\t%ld\n",
			ft_strlcat(argv[2], argv[3], atoi(argv[1])));
	}
	return (0);
}
