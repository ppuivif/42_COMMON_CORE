int	ft_strlen(char *str)
{
	int i = 0;

	while(str[i])
		i++;
	return (i);
}

char *ft_strrev(char *str)
{
	int i = 0;
	int j = ft_strlen(str) - 1;
	char tab[ft_strlen(str)];

	while (str[i])
	{
		tab[j] = str[i];
		i++;
		j--;
	}
	tab[ft_strlen(str)] = 0;
	char *p = tab;
	return(p);
}

#include <stdio.h>

int main()
{
	char str[] = "abcdefghijklmnopqrstuvw";
	printf("%d\n", ft_strlen(str));
	printf("%s\n", ft_strrev(str));
	return (0);
}
