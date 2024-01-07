/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove_mained.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:17:12 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/13 14:47:07 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*desti;
	unsigned char	*srci;
	size_t			i;

	desti = (unsigned char *) dest;
	srci = (unsigned char *) src;
	i = 0;
	if (srci == 0 && desti == 0)
		return (0);
	while (i < n)
	{
		if (srci >= desti)
		{
			desti[i] = srci[i];
			i++;
		}
		while (n != 0)
		{
			desti[n - 1] = srci[n - 1];
			n--;
		}
	}
	return (desti);
}

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		printf("real_function :\n");
		printf("\tsize :\t\t%s\n", argv[3]);
		printf("\tsource :\t%s\n", argv[2]);
		printf("\tdestination :\t%s\n", argv[1]);
		memmove(argv[1], argv[2], atoi(argv[3]));
		printf("\tdestination after function :\t%s\n", argv[1]);
		printf("\tfunction_return :\t%p\n",
			memmove(argv[1], argv[2], atoi(argv[3])));
	}
	if (argc == 5)
	{
		printf("ft_function :\n");
		printf("\tsize :\t\t%s\n", argv[3]);
		printf("\tsource :\t%s\n", argv[2]);
		printf("\tdestination :\t%s\n", argv[1]);
		ft_memmove(argv[1], argv[2], atoi(argv[3]));
		printf("\tdestination after function :\t%s\n", argv[1]);
		printf("\tfunction_return :\t%p\n",
			ft_memmove(argv[1], argv[2], atoi(argv[3])));
	}
	return (0);
}
