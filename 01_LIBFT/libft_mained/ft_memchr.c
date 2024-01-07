/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:16:44 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/12 16:30:36 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	d;

	i = 0;
	str = (unsigned char *) s;
	d = (unsigned char) c;
	while (i < n)
	{
		if (str[i] == d)
			return (str + i);
		else
			i++;
	}
	return (0);
}
