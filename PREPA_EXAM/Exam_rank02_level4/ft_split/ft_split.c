#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

void    *ft_free(char **tab)
{
	int	i = 0;

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

static int  count_words(const char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (!str)
        return (0);
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
    while (str[i])
    {
		while(str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			i++;
		count++;
		while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
    }
	return (count);
}

static size_t ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return ((size_t)i);
}

static size_t len_str(const char *str, int start)
{
	int	i;

	i = start;
	while (str && str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		i++;
	return ((size_t)(i - start));
}

static int	start_word(const char *str, int count)
{
	int	i;
	int nbr;

	i = 0;
	nbr = 1;
	if (!str)
		return (0);
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
    while (str[i])
    {
		while(str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			if (nbr == count)
				return (i);
			i++;
		}
		nbr++;
		while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;//		printf("%c", s[i]);

    }
	return (0);
}

/*char	*ft_strdup(const char *str)
{		s[0] = 0;


	if(!str)
		return (NULL);
	len = ft_strlen(str);
	s = malloc(((int)len + 1) * sizeof(char));
	if(!s)
		return(NULL);
	while (i <= (int)len)
	{
		s[i] = str[i];
		i++;
	}

	s[i] = 0;
	return (s);
}*/

char *ft_substr(const char *str, unsigned int start, size_t len)
{
	unsigned int		i;
	unsigned int		j;
	char	*s;

	i = start;
	j = 0;
	if (!str)
		return (NULL);
	if (start > ft_strlen(str))
		return (NULL);
	if (len > ft_strlen(str))
		len = ft_strlen(&str[start]);
//	if (len > ft_strlen(&str[start]))
//		len = 0;
	s = malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (j < len && str[i])
	{
		s[j] = str[i];
		j++;
		i++;
	}
	s[j] = 0;
	return(s);
}

char    **ft_split(const char *str)
{
	char **tab;
	int count;
	int start;
	int len;
	
	if(!str)
		return (NULL);
	tab = malloc(count_words(str) * sizeof(char *));
	if (!tab)
		return (NULL);
	count = 0;
	start = 0;
	len = 0;
	while (count < count_words(str))
	{
		start = start_word(str, count + 1);
		len = (int)len_str(str, start);
		tab[count] = ft_substr(str, start, len);
		if(!tab[count])
			return (ft_free(tab));
		count++;
	}
	tab[count] = NULL;
	return(tab);
}

#include <stdio.h>

int	main()
{
	int i;
	const char *str = "  abcd\nmr  efgh	ijkl\n";

	char **tab = ft_split(str);
	i = 0; 
	while (i < count_words(str))
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return(0);
}
