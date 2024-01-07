/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:32:00 by ppuivif           #+#    #+#             */
/*   Updated: 2024/01/04 10:23:57 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
void	ft_swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;	
}


char	*ft_strrev(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		ft_swap(&str[i], &str[j]);
		j--;
		i++;
	}
	return (str);
}
*/


char	*ft_strrev(char *str)
{
	int	i;
	int	j;
	int	len;
//	char	tmp[ft_strlen(str) + 1];
	char	c;

	len = ft_strlen(str);
	i = 0;
	j = len - 1;
	while (i < j)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
	return (str);
}
/*	while (i <= len - 1)
	{
		tmp[i] = str[j];
		i++;
		j--;
	}
	tmp[j] = '\0';
	str = tmp;
	return (str);
}*/


#include <stdio.h>
#include <string.h>

int	main(void)
{
//	char	str[] = "abcdefg";//declaration et initialisation sur une meme ligne
	char	str[8];

	strcpy(str, "abcdefg");
	printf("%s", ft_strrev(str));
	return (0);
}
