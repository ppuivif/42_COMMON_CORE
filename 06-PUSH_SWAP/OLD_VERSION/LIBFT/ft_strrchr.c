/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:14:33 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/15 10:01:52 by ppuivif          ###   ########.fr       */
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
