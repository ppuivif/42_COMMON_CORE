/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_mained.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:27:17 by ppuivif           #+#    #+#             */
/*   Updated: 2023/11/22 15:05:16 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_count_words(char const *s, char c)
{
	int		count;
	size_t	i;

	count = 1;
	i = 0;
	if (!s)
		count = 0;
	while (i < ft_strlen(s) - 1)
	{
		if (s[i] == c)
		{
			count++;
			i++;
		}
		i++;
	}
	return (count);
}

static int	ft_start_str(char const *s, char c, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (count == 1)
		return (0);
	while (j < count - 1)
	{
		if (s[i] == c && s[i + 1] != c)
		{
			j++;
			i++;
		}
		i++;
	}
	return (i - 1);
}

static int	ft_len_str(char const *s, char c, int start)
{
	int	i;

	i = start;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
	}
	return (i - start);
}

char	**ft_split(char const *s, char c)
{
	int		start;
	int		len;
	int		i;
	char	**tab;

	if (ft_count_words(s, c) == 0)
		return (NULL);
	else
	{
		tab = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
		if (!tab)
			return (NULL);
		else
		{
			while (s[i] == c && s[i] != '\0')
				i++;
			i = 0;
			while (i < ft_count_words(s, c))
			{
				start = ft_start_str(s, c, i + 1);
				len = ft_len_str(s, c, start);
				tab[i] = ft_substr(s, start, len);
				i++;
			}
			tab[i] = NULL;
			return (tab);
		}
	}1
}

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc > 0)
	{
		int	i = 0;
		char	**tab = ft_split(argv[1], argv[2][0]);
		printf("function return : \n");
		while (tab[i])
		{
			printf("%s\n", tab[i]);
			i++;
		}

	}
	return (0);
}

/*#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc > 0)
	{
		printf("count is : %d\n", ft_count_words(argv[1], argv[2][0]));
		printf("index of start is : %d\n",
			ft_start_str(argv[1], argv[2][0], atoi(argv[3])));
		printf("length of word is : %d\n",
			ft_len_str(argv[1], argv[2][0], atoi(argv[4])));
	}
	return (0);
}*/

