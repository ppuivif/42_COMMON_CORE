/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   added_functions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:29:45 by ppuivif           #+#    #+#             */
/*   Updated: 2023/12/08 11:53:56 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_hexa_lower(unsigned int n)
{
	char	*tab;
	int		i;

	tab = "0123456789abcdef";
	i = 0;
	if (n >= 16)
		i = ft_hexa_lower(n / 16);
	i += 1;
	write (1, &tab[n % 16], 1);
	return (i);
}

int	ft_hexa_upper(unsigned int n)
{
	char	*tab;
	int		i;

	tab = "0123456789ABCDEF";
	i = 0;
	if (n >= 16)
		i = ft_hexa_upper(n / 16);
	i += 1;
	write (1, &tab[n % 16], 1);
	return (i);
}
