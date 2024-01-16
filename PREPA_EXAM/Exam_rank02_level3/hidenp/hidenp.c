/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:04:59 by ppuivif           #+#    #+#             */
/*   Updated: 2024/01/09 19:34:44 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(char *str)
{
	size_t i = 0;
	while (str[i])
		i++;
	return (i);
}

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	int flag = 0;
	
    if (argc == 3)
    {
		while (argv[1][j])
		{
			while (argv[2][i] && flag < j + 1)
			{	
				if (argv[2][i] == argv[1][j])
					flag += 1;
				i++;
			}
			j++;
		}
		if (flag == (int)ft_strlen(argv[1]))
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
    write(1, "\n", 1);
}

