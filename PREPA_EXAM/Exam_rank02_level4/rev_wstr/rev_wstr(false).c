#include <unistd.h>
#include <stdlib.h>

char **ft_free(char **tab)
{
	int i = 0;
	
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

	while(str && str[len])
		len++;
	return(len);
}

int ft_count_word(char *str)
{
	int i = 0;
	int count = 0;

	while (str && str[i])
	{
		if (str[i] != 32)
			i++;
		if (str[i] == 32 || str[i+1] == '\0')
		{
			count++;
			i++;
		}
	}
	return (count);
}

int ft_start(char *str, int count)
{
	int i = 0;
	int flag = 0;

	while (str && str[i])
	{
		if (str[i] != 32)
			flag++;
		if (flag == count)
			return (i);
		while (str[i] != 32)
			i++;
		if (str[i] == 32 || str[i+1] == '\0')
			i++;
	}
	return(0);
}

int ft_len_word(char *str, int start)
{
	int i = start;

	if (!str)
		return (0);
	while (str[i] && str[i] != 32)
			i++;
	return (i - start);
}
char *ft_substr(char *str, int start, size_t len)
{
	char *s;
	unsigned int i = 0;

	if (!str)
		return (NULL);
	if (start > (int)ft_strlen(str))
		return (NULL);
	if (len > ft_strlen(&str[start]))
		len = ft_strlen(&str[start]);
	s = malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (i < len && str[start + i])
	{
		s[i] = str[start + i];
		i++;
	}
	s[i] = '\0';
	return (s);
}


char **rev_wstr(char *str)
{
	int nb_word = ft_count_word(str);
	int i = nb_word;
	char **tab;
	int start = 0;
	//int len_word = 0;

	if(!str)
		return (NULL);	
	tab = malloc((nb_word) * sizeof(char *));
	if (!tab)
		return (NULL);	
	tab[nb_word] = '\0';
	while (i >= 0)
	{
		start = ft_start(str, i);
		//len_word = ft_len_word(str, i - 1);
		tab[i] = ft_substr(str, start, ft_len_word(str, i));
		if(tab[i])
			return(ft_free(tab));
		i--;
	}
	return (tab);
}


#include <stdio.h>

/*int main (int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 0;
		char **tab = rev_wstr(argv[1]);
		while (i < ft_count_word(argv[1]))
		{
			printf("%s", tab[i]);
			i++;
//			printf("%d", ft_count_word(argv[1]));
//			printf("%s", ft_substr(argv[1], 5, 5));
//			printf("%d", ft_start(argv[1], 3));
		}
	}
	write(1, "\n", 1);
	return (0);
}*/

//int main (int argc, char **argv)
int main()
{
//	if (argc == 2)
//	{
		int i = 0;
//		char **tab = rev_wstr(argv[1]);
		char **tab = rev_wstr("abcdefg ijklmn");
//		while (i < ft_count_word(argv[1]))
		while (i < ft_count_word("abcdefg ijklmn"))
		{
			printf("%s", tab[i]);
			i++;
//			printf("%d", ft_count_word(argv[1]));
//			printf("%s", ft_substr(argv[1], 5, 5));
//			printf("%d", ft_start(argv[1], 3));
//			printf("%d", ft_len_word(argv[1], 1));
		}
//	}
//	write(1, "\n", 1);
	return (0);
}