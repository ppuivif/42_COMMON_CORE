/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_mained.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:03:15 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/21 19:55:37 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s != 0)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc > 0)
	{
		ft_putstr_fd(argv[1], atoi(argv[2]));
		printf("\n");
	}
	return (0);
}
