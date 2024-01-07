/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_mained.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:14:09 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/09 10:24:38 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*e;
	size_t			i;

	e = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		e[i] = c;
		i++;
	}
	return (s);
}

#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	int n = 2;
	int c = 'r';
	int d = 'f';

	if (argc > 0)
	{
		memset(argv[1], c, n);
		printf("result of real_function\t%s\n", argv[1]);
		printf("real_function_return\t%p\n", memset(argv[1], c, n));
		ft_memset(argv[1], d, n);
		printf("result of ft_function\t%s\n", argv[1]);
		printf("ft_function_return\t%p\n", ft_memset(argv[1], d, n));
	}
	return (0);
}
