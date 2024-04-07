/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_freed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:25:36 by ppuivif           #+#    #+#             */
/*   Updated: 2024/04/07 18:23:49 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_freed(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	str = malloc((len + 1) * sizeof(char));
	if (str)
	{
		while (i < (unsigned int)len)
		{
			str[i] = s[start + i];
			i++;
		}
		str[i] = 0;
		free(s);
		s = NULL;
		return (str);
	}
	return (NULL);
}
