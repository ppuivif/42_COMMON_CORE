/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:29:45 by ppuivif           #+#    #+#             */
/*   Updated: 2023/12/16 15:25:21 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

/*int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[i])
		i++;
	return (i);
}

*/void	ft_putstr(char *s)
{
	int 	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}
/*
char	*ft_create_str(char *s)
{
	char	*str;
	int	i;
*
	i = 0;
	while (i < 8)
	{
		str[i] = 48;
		i++;
	}

	while (i > (8 - ft_strlen(i)))
	{	
		str[i]
	}

}

*/int	fill_bits(unsigned char octet, char *s)
{
	int	i;

	i = 0;
	if(octet >= 2)
	 	i = fill_bits(octet / 2, s);
	i += 1;
	s[i] = (octet % 2 + '0');
	ft_putstr(s);
	return (i);
}

/*void	print_bits(unsigned char octet)
{
	char	s[8];
	int 	i;
	int 	j;

	fill_bits(octet, &s);
	i = 0;
	j = 0;
	while (i < 8)
	{
		if (i < (8 - fill_last_bits(octet)))	
			s[i] = 48;
		else
		{
			s[i] = str[j];
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 8)
		write(1, &s[i], 1);s
}*/


int	main(int argc, char **argv)
{
	char	s[8];
	if (argc > 1)
		fill_bits(atoi(argv[1]), &s);
}
