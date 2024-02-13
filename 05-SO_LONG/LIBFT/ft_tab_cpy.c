/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:27:59 by ppuivif           #+#    #+#             */
/*   Updated: 2024/02/13 16:30:24 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tab_cpy(char **tab, unsigned int nb_lines, unsigned int nb_columns)
{
	unsigned int	i;
	unsigned int	j;
	char			**tab_cpy;

	if (!tab)
		return (0);
	j = 0;
	tab_cpy = ft_calloc(nb_lines, sizeof(char *));
	if (!tab_cpy)
		return (0);
	while (j < nb_lines && tab[j])
	{
		i = 0;
		tab_cpy[j] = ft_calloc(nb_columns, sizeof(char));
		if (!tab_cpy[j])
			return (0);
		while (i < nb_columns && tab[j][i])
		{
			tab_cpy[j][i] = tab[j][i];
			i++;
		}
		j++;
	}
	return (tab_cpy);
}
