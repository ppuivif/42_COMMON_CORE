/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits_rev2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 08:33:05 by ppuivif           #+#    #+#             */
/*   Updated: 2023/12/19 08:43:01 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse bits(unsigned char octet)
{
	int	i;
	unsigned char res

	i = 8;
	res = 0;
	while (i >= 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		write (1, &res, 1);
		i--;
	}
	return (res);
}
