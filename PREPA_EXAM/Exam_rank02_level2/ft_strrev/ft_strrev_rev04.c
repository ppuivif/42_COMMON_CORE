#include <stddef.h>

size_t	ft_strlen(char *str)
{
	size_t i = 0;

	while (str && str[i])
		i++;
	return (i);
}



char	*ft_strrev(char *str)
{
	char c;
	int j = (int)ft_strlen(str) - 1;
	int i = 0;

	while (i < j)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
	return (str);
}

#include <stdio.h>

int main()
{
	char str[] = "abcdefghij";

	printf("%s", ft_strrev(str));
}