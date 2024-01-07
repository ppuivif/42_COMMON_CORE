/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:57:07 by ppuivif           #+#    #+#             */
/*   Updated: 2023/12/07 12:49:46 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar_i_j(char c, int i, int j)
{
	while(c && j > 0)
	{
		write(1, &c, 1);
		j--;
		i++;
	}
	return (i-1);
}



int	main(int argc, char **argv)
{
	int	i;
	int	j;
	char	*str;

	if(argc > 1)
	{
		str = argv[1];
		if(str != NULL)
		{
			i = 0;
			while(str[i])
			{
				if(str[i] >= 97 && str[i] <= 122)
				{
					j = str[i] - 96;
//					ft_putchar_i_j(str[i], i, j);
					i = ft_putchar_i_j(str[i], i, j);
				}
				else
					write(1, &str[i], 1);
				i++;
			}
			write(1, "\n", 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
