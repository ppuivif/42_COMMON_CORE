/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_mained.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:09:34 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/16 09:34:17 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char	const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		j;
	char		*str;

	i = start;
	j = 0;
	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(&s[start])))
		len = ft_strlen(&s[start]);
	str = (char *)malloc((len + 1) * sizeof (char));
	if (str)
	{
		while (j < len && s[i] != '\0')
		{
			str[j] = s[i];
			j++;
			i++;
		}
		str[j] = '\0';
		return (str);
	}
	return (NULL);
}

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc > 0)
	{
		printf("ft_function return :%p\n",
			ft_substr(argv[1], atoi(argv[2]), atoi(argv[3])));
		printf("ft_function return :%s\n",
			ft_substr(argv[1], atoi(argv[2]), atoi(argv[3])));
	}
	return (0);
}
