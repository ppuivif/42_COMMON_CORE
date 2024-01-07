/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:33:58 by ppuivif           #+#    #+#             */
/*   Updated: 2023/12/18 11:56:48 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 

void	print_bits(unsigned char octet)
{
	int	i;
	unsigned char	bit;

	i = 8;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write (1, &bit, 1);
//		i--;
	}
}



unsigned char	reverse_bits(unsigned char octet)
{
	int	i;
	unsigned char res;

	i = 8;
	res = 0;
	while (i >= 0)// plutot > 0 a priori
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		write (1, &res, 1);
		i--;
	}
	return (res);

}

#include <stdio.h>

int	main()
{
	unsigned char	i;

	i  = '2';
	print_bits(i);
	write(1, "\n", 1);
//	reverse_bits(i); ne fonctionne pas
}

