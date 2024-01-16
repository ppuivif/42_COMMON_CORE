int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return (i);
}

void ft_swap(char *a, char *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

char *ft_strrev(char *str)
{
	int i = 0;
	int j = ft_strlen(str) - 1;

	while (i < j)
	{
		ft_swap(&str[i], &str[j]);
		i++;
		j--;
	}
	return (str);
}

#include <stdio.h>

int main()
{
	char str[] = "abcdefghijklmnopqrstuvw";
	printf("%d\n", ft_strlen(str));
	printf("%s\n", ft_strrev(str));
	return (0);
}