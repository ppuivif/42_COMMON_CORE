/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:45:03 by ppuivif           #+#    #+#             */
/*   Updated: 2023/12/16 17:52:26 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}




#include <string.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("re %ld\n", strcspn(argv[1], argv[2]));
		printf("ft %ld\n", ft_strcspn(argv[1], argv[2]));
	}
	return (0);
}
