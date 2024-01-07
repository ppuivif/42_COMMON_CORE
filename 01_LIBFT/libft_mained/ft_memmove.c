/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:17:12 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/13 14:44:58 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;

	i = 0;
	if ((unsigned char *) dest == 0 && (unsigned char *) src == 0)
		return (0);
	while (i < n)
	{
		if ((unsigned char *) src >= (unsigned char *) dest)
		{
			((unsigned char *) dest)[i] = ((unsigned char *) src)[i];
			i++;
		}
		else
		{
			while (n != 0)
			{
				((unsigned char *) dest)[n - 1]
					= ((unsigned char *) src)[n - 1];
				n--;
			}
		}
	}
	return ((unsigned char *)dest);
}
