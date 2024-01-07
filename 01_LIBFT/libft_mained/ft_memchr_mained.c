/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_mained.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:16:44 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/12 16:29:08 by ppuivif          ###   ########.fr       */
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

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 4)
		printf("real_function give :\t%s\n",
			(char *)memchr(argv[1], atoi(argv[2]), atoi(argv[3])));
	if (argc == 5)
		printf("ft_function give :\t%s\n",
			(char *)ft_memchr(argv[1], atoi(argv[2]), atoi(argv[3])));
	return (0);
}
