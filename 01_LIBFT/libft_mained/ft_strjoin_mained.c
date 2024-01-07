/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_mained.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:45:47 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/23 17:23:33 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_fill_str(char *s1, const char *s2, int i, int j)
{
	while (s2[j] != '\0')
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;


	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof (char));
	if (!str)
		return (NULL);
	else
	{
		ft_fill_str(str, s1, i, i);
		i = ft_strlen(str);
		ft_fill_str(str, s2, i, j);
		i = ft_strlen(str);
		return (str);
	}
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc > 0)
	{
		printf("str_prefixe :\t%s\n", argv[1]);
		printf("str_suffixe:\t%s\n", argv[2]);
		printf("function return :\t%s\n", ft_strjoin(argv[1], argv[2]));
	}
	return (0);
}
