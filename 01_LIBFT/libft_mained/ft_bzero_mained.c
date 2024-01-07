/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_mained.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:55:23 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/09 12:04:53 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*e;
	size_t			i;

	i = 0;
	e = (unsigned char *) s;
	while (i < n)
	{
		e[i] = '\0';
		i++;
	}
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		bzero(argv[2], atoi(argv[1]));
		printf("real_function : nothing to print because "
			"first byte is null\t%s\n", argv[2]);
	}
	if (argc == 4)
	{
		ft_bzero(argv[2], atoi(argv[1]));
		printf("ft_function : nothing to print because "
			"first byte is null\t%s\n", argv[2]);
	}
	return (0);
}
