/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri_mained.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:24:06 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/22 17:54:28 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_striteri(char *s, void (*f)(char))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(s[i]);
		i++;
	}
}

int	main(void)
{
	char	str[] = "CHRIS";

	ft_striteri(str, ft_putchar);
}
