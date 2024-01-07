/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 07:47:25 by ppuivif           #+#    #+#             */
/*   Updated: 2023/12/22 08:29:06 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}


void	ft_putstr(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(1, &(str[0]), len);
}

char	*epur_str(char *str)
{
	int	i;
	char	*s;

	i = 0;
	while (str[i])
	{
		if ((str[i] != 32 || str[i] != 9))
			s[i] = str[i];
		else if (str[i + 1] && (str[i] == 32 || str[i] == 9)
			&& (str[i + 1] != 32 || str[i + 1] != 9))
			s[i] = str[i];
		else 
			i++;
		i++;
	}
	return (s);

}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_putstr(argv[1]);
		ft_putstr(epur_str(argv[1]));
	}
	write(1, "\n", 1);
	return (0);
}
