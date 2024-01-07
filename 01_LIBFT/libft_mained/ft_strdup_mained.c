/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_mained.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:13:53 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/15 18:02:37 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	str = (char *)malloc(len + 1);
	if (str)
	{
		while (i <= len)
		{
			str[i] = s[i];
			i++;
		}
		return (str);
	}
	return (0);
}

#include <string.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("real_function return :\t%p\n", strdup(argv[1]));
		printf("real_function return :\t%s\n", strdup(argv[1]));
	}
	if (argc == 3)
	{
		printf("ft_function return :\t%p\n", ft_strdup(argv[1]));
		printf("ft_function return :\t%s\n", ft_strdup(argv[1]));
	}
	return (0);
}
