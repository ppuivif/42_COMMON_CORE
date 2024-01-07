/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_mained.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:14:33 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/23 14:45:30 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	d;

	str = (char *) s;
	i = ft_strlen(str);
	d = (char) c;
	if (d == 0)
		return (str + i);
	while (i >= 0)
	{
		if ((unsigned char)str[i] == (unsigned char)d)
			return (str + i);
		else
			i--;
	}
	return (0);
}

#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
		printf("real_function give :\t%s\n", strrchr(argv[1], argv[2][0]));
	if (argc == 4)
		printf("ft_function give :\t%s\n", ft_strrchr(argv[1], argv[2][0]));
	return (0);
}
