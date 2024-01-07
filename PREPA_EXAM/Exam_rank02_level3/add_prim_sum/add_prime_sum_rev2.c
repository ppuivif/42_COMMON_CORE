/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum_rev2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 08:51:04 by ppuivif           #+#    #+#             */
/*   Updated: 2023/12/19 11:57:05 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

void	ft_putnbr(int	nbr)
{
	char	c;

	if (nbr == INT_MIN)
		write (1, "-2147483648", 11);
	else if (nbr < 0)
	{
		nbr *= -1;
		write (1, "-", 1);
	}
	else if (nbr > 9)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write (1, &c, 1);
}

int	ft_atoi(const char *s)
{
	int	i;
	int	j;
	int nbr;

	i = 0;
	j = 1;
	nbr = 0;
	while (s[i] && (s[i] == 32 || (s[i] > 8 && s[i] < 14)))
		i++;
	if (s[i] && (s[i] == 45 || s[i] == 43))
	{
		if (s[i] == 45)
			j = j * -1;
		i++;
	}
	while (s[i] && s[i] > 47 && s[i] < 58)
	{
		nbr = (nbr * 10) + (s[i] - 48);
		i++;
	}
	return (nbr * j);
}

int	ft_is_prime(int nbr)
{
	int	i;

	i = 2;
	if (nbr < 2)
		return (0);
	while ((i * i) <= nbr)
	{
		if (nbr % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	add_prime_sum(int nb)
{
	int	sum;
	int	i;

	sum = 0;
	i = 0;
	while (i <= nb)
	{
		if (ft_is_prime(i) == 1)
			sum += i;
		i++;
	}	
	ft_putnbr(sum);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	int i;

	i = ft_atoi(argv[1]); 
	if (argc == 2 && i > 0)
		add_prime_sum(i);
	else
		write(1, "0", 1);
	write(1, "\n", 1);//seg_fault si pas de valeur
	return (0);
}
