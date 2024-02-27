/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:47:20 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/14 19:21:55 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	m;
	size_t	n;

	i = 0;
	m = ft_strlen(src);
	if (size == 0)
		return (m);
	n = ft_strlen(dst);
	if (n >= size)
		return (m + size);
	while (src[i] && (n + i) < size - 1)
	{
		dst[n + i] = src[i];
		i++;
	}
	dst[n + i] = '\0';
	return (n + m);
}
