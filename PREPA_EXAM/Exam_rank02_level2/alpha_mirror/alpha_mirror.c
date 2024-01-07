/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:29:06 by ppuivif           #+#    #+#             */
/*   Updated: 2023/12/16 15:58:32 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	alpha_mirror(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'm')
			s[i] = 'z' - (s[i] - 'a');
		else if (s[i] >= 'A' && s[i] <= 'M')
			s[i] = 'Z' - (s[i] - 'A');
		else if (s[i] >= 'n' && s[i] <= 'z')
			s[i] = 'a' + ('z' - s[i]);
		else if (s[i] >= 'N' && s[i] <= 'Z')
			s[i] = 'A' + ('Z' - s[i]);
		write(1, &s[i], 1);
		i++;
	}
}




int	main(int argc, char **argv)
{
	if (argc > 1)
		alpha_mirror(argv[1]);
	return (0);
}
