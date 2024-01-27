/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:31:41 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/13 15:26:47 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*desti;
	unsigned char	*srci;
	size_t			i;

	desti = (unsigned char *) dest;
	srci = (unsigned char *) src;
	i = 0;
	if (desti == 0 && srci == 0)
		return (0);
	while (i < n)
	{
		desti[i] = srci[i];
		i++;
	}
	return (desti);
}
