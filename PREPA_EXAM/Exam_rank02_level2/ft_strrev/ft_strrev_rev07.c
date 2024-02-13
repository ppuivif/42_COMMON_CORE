#include <stddef.h>

size_t ft_strlen (char *str)
{	
	size_t	len = 0;

	while (str && str[len])
		len++;
	return (len);
}

char	*ft_strrev(char *str)
{
	int i = 0;
	char tmp;
	int j = ft_strlen(str) - 1;

	while (i < j)
	{
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
		i++;
		j--;
	}
	return (str);
}
#include <stdio.h>

int main()
{
	char str[] = "abcdef";

	printf("%s", ft_strrev(str));
	return(0);
}