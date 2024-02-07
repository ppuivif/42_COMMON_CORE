#include <stdlib.h>

void	*free_tab(char **tab)
{
	int i = 0;

	if (!tab)
		return (NULL);
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}	
	free(tab);
	tab = NULL;
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t len = 0;

	while (str && str[len])
		len++;
	return (len);
}

size_t	ft_len_word(char *str, int start)
{
	int i = start;

	while (str && str[i] && str[i] != 32 && str[i] != '\t' && str[i] != '\n')
		i++;
	return (i - start);
}

int	count_words(char *str)
{
	int i = 0;
	int nb_words = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] && (str[i] == 32 || str[i] == '\n' || str[i] == '\t'))
			i++;
		if (str[i])
			nb_words++;
		while (str[i] && str[i] != 32 && str[i] != '\n' && str[i] != '\t')
			i++;
	}
	return (nb_words);
}

int	ft_start_word(char *str, int index_word)
{
	int i = 0;
	int count = 1;

	if (!str)
		return (0);
	while (str[i] && (str[i] == 32 || str[i] == '\n' || str[i] == '\t'))
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != 32 && str[i] != '\n' && str[i] != '\t')
		{
			if (count == index_word)
				return (i);
			i++;
		}
		count ++;
		while (str[i] == 32 && str[i] == '\n' && str[i] == '\t')
			i++;
	}
	return (0);
}

char *substr(char *str, unsigned int start, size_t len)
{
	unsigned int i;
	unsigned int j;
	char	*s;
	
	j = 0;
	i = start + j;
	if (!str || start > ft_strlen(str))
		return (NULL);
	if (len > ft_strlen(str))
		len = ft_strlen(&str[start]);
	s = malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[len] = '\0';
	while (i < len && str[i])
	{
		s[j] = str[i];
		j++;
	}
	return (s);
}

char	**ft_split(char *str)
{
	int i = 0;
	char **tab;
	int nb_words = count_words(str);
	int start = 0;
	unsigned int len_word = 0;

	if(!str)
		return (NULL);
	tab = malloc((nb_words + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab[nb_words] = 0;
	while (i < nb_words)
	{
		start = ft_start_word(str, i);
		len_word = ft_len_word(str, start);
		tab[i] = substr(str, start, len_word);
		if (!tab[i])
			return (free_tab(tab));
		i++;
	}
	return (tab);
}

#include <stdio.h>

int main()
{
	int i = 0;
	char *str = "premier 	deuxieme troisieme quatrieme\n";
	char **tab = ft_split(str);

	while (*tab[i])
	{
		printf("%s", tab[i]);
		i++;
	}
	return (0);
}