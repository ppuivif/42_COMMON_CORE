/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:50:08 by ppuivif           #+#    #+#             */
/*   Updated: 2023/12/12 18:29:23 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		int	j;
	
		j = ft_strlen(argv[1]);
		while (j)
			write(1, &argv[1][--j], 1);
	}
	write(1, "\n", 1);
	return (0);
}
