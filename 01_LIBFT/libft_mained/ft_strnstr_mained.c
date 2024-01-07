/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_mained.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:09:33 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/16 09:45:40 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!little[i])
		return ((char *) big);
//	if (len == 0 || ft_strlen(little) > len)
//		return (0);
	while (i < len && big[i] != '\0')
	{
		k = i;
		while (big[i] == little[j] && i < len && big[i])
		{
			i++;
			j++;
		}
		if (little[j] == '\0')
			return ((char *)big + i - j);
		j = 0;
		i = k;
		i++;
	}
	return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		printf("real_function return :\n");
		printf("\tbig :\t%s\n", argv[1]);
		printf("\tlittle:\t%s\n", argv[2]);
		printf("\tsize :\t%d\n", atoi(argv[3]));
		printf("\tfunction_return :\t%s\n",
			strnstr(argv[1], argv[2], atoi(argv[3])));
	}
	if (argc == 5)
	{
		printf("ft_function return :\n");
		printf("\tbig :\t%s\n", argv[1]);
		printf("\tlittle:\t%s\n", argv[2]);
		printf("\tsize :\t%d\n", atoi(argv[3]));
		printf("\tfunction_return :\t%s\n",
			ft_strnstr(argv[1], argv[2], atoi(argv[3])));
	}
	return (0);
}
