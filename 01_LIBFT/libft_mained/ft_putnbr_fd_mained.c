/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_mained.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:53:27 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/23 10:37:39 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*int	ft_count_int(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		n *= -1;
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}*/


void	ft_putnbr_fd(int n, int fd)
{
//	int	i;
//	char	c[ft_count_int(n)];
	char	c; 
//	i = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -1 * n;
	}
	if (n > 9)
	{
//		i = ft_count_int(n) - 1;
		ft_putnbr_fd(n / 10, fd);
	}
	c = n % 10 + '0';
	write (fd, &c, 1);
}









/*			c[i] = n % 10 + '0';
			n = n / 10;	
			i--;
		}
		c[0] = n + '0';
		ft_putstr_fd(c, fd);
	}
}*/

#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc > 0)
	{
//		printf("count i : %d\n", ft_count_int(atoi(argv[1])));
		ft_putnbr_fd(atoi(argv[1]), atoi(argv[2]));
	}
	return (0);
}
