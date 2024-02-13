/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:48:10 by ppuivif           #+#    #+#             */
/*   Updated: 2024/02/12 09:14:37 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	first_word(char *s)
{
	int	i;

	i = 0;
	while (s[i] == 32 || s[i] == 9)
		i++;
	while (s[i] != 32 && s[i] != 9 && s[i] != '\0')
	{
		write (1, &s[i], 1);
		i++;
	}
	write (1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		first_word(argv[1]);
	}
	else
		write(1, "\n", 1);
	return (0);
}
