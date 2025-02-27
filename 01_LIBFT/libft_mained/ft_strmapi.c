/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:26:01 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/23 12:42:24 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s || !f)
		return (NULL);
	i = 0;
	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	else
	{
		while (s[i] != '\0')
		{
			str[i] = f(i, s[i]);
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}

char    ft_chchr(unsigned int n, char c)
{
    if (c < 86)
        c = 'a' + n;
    else
        c = 'b' + n;
    return (c);
}

#include <stdio.h>

int    main(int ac, char **av)
{
    char    *tab;
    (void)ac;

    if (ac == 2)
        tab = ft_strmapi(av[1], ft_chchr);
    printf("%s", tab);
    free(tab);
    return (0);
}
