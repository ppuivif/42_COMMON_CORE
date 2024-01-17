#include <stddef.h>

size_t	ft_strlen(char *str)
{
	size_t	len = 0;

	while (str && str[len])
		len++;
	return(len);
}


void ft_swap(char *a, char *b)
{
	char c;

	c = *a;
	*a = *b;
	*b = c;
}

char	*ft_strrev(char *str)
{
	unsigned int i = 0;
	unsigned int j = ft_strlen(str) - 1;
	
	if (!str)
		return (str);
	while (i < j)
	{
		ft_swap(&str[i], &str[j]);
		i++;
		j--;
	}
	return (str);
}

#include <stdio.h>

int	main()
{	
	char str[] = "abdefgh";

	printf("%s\n", ft_strrev(str));
	return (0);
}
