/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_mained.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:31:41 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/13 15:31:51 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*desti;
	unsigned char	*srci;
	size_t			i;

	desti = (unsigned char *) dest;
	srci = (unsigned char *) src;
	i = 0;
	if (desti[i] == '\0' && srci[i] == '\0')
		return (0);
	while (i < n)
	{
		desti[i] = srci[i];
		i++;
	}
	return (desti);
}

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		printf("real_function :\n");
		printf("\tsize :\t\t%s\n", argv[1]);
		printf("\tsource :\t%s\n", argv[3]);
		printf("\tdestination :\t%s\n", argv[2]);
		memcpy(argv[2], argv[3], atoi(argv[1]));
		printf("\tdestination after function :\t%s\n", argv[2]);
	}
	if (argc == 5)
	{
		printf("ft_function :\n");
		printf("\tsize :\t\t%s\n", argv[1]);
		printf("\tsource :\t%s\n", argv[3]);
		printf("\tdestination :\t%s\n", argv[2]);
		ft_memcpy(argv[2], argv[3], atoi(argv[1]));
		printf("\tdestination after function :\t%s\n", argv[2]);
	}
	return (0);
}
