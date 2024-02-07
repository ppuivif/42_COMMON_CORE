#include <stddef.h>

size_t	ft_strlen(char *str)
{
	size_t i = 0;
	while(str && str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strrev(char *str)
{
	char c;
//	char *tmp;
	unsigned int i = 0;
	size_t len = ft_strlen(str);

	while (i <= (len / 2))
	{
		c = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = c;
		i++;
	}
	return (str);
}
#include <stdio.h>

int	main()
{
	//char *str;
	char str [] = "abcdefgh";
	ft_strrev(str);
	printf("%s", str);
	return (0);
}