/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_mained.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:18:34 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/15 10:05:32 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = nmemb * size;
	if (!size || !nmemb)
		return (malloc(1));
	if (j > __SIZE_MAX__ || (size > 65535 && nmemb > 65535))
		return (NULL);
	str = (char *)malloc(j);
	if (str)
	{
		while (i < j)
		{
			str[i] = '\0';
			i++;
		}
		return ((void *) str);
	}
	return (NULL);
}

#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("real_function return :\t%p\n",
			calloc(atoi(argv[1]), atoi(argv[2])));
	}
	if (argc == 4)
	{
		printf("ft_function return :\t%p\n",
			ft_calloc(atoi(argv[1]), atoi(argv[2])));
	}
	return (0);
}
