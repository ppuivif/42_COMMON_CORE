/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_mained.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:39:46 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/20 09:10:36 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_start(char const *s1, char const *set)
{
	int	start;
	int	i;
	int	j;

	start = 0;
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				start++;
				j = 0;
				i++;
			}
			else
				j++;
		}
		i++;
	}
	return (start);
}

int	ft_end(char const *s1, char const *set)
{
	int	end;
	int	i;
	int	j;

	end = 0;
	i = ft_strlen(s1) - 1;
	j = 0;
	while (i > 0)
	{
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				end++;
				j = 0;
				i--;
			}
			else
				j++;
		}
		i--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		len;

	str = (char *) s1;
	len = ft_strlen(s1) - ft_start(s1, set) - ft_end(s1, set);
	if (!s1 && !set)
		return (NULL);
	else
	{
		if (len <= 0)
			return (NULL);
		return (str = ft_substr(s1, ft_start(s1, set), len));
	}
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc > 0)
	{
		printf("function return :\t%s\n", ft_strtrim(argv[1], argv[2]));
		printf("size of return is :\t%s\n",
			ft_strlen(ft_strtrim(argv[1], argv[2])));
	}
	return (0);
}
