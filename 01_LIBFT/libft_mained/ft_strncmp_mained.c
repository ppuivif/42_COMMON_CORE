/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_mained.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:00:49 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/12 14:38:18 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while (i < n)
	{
		if ((str1[i] == str2[i]) && (str1[i] != '\0') && (str2[i] != '\0'))
			i++;
		else
			return (str1[i] - str2[i]);
	}
	return (0);
}

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 4)
		printf("real_function return :\t%d\n",
			strncmp(argv[1], argv[2], atoi(argv[3])));
	if (argc == 5)
		printf("ft_function return :\t%d\n",
			ft_strncmp(argv[1], argv[2], atoi(argv[3])));
	return (0);
}
