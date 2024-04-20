#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char *result;
	unsigned int i;

	if (!s)
		return (NULL);
	result = s;
	i = 0;
	while (result[i] && c && i < n)
	{
		result[i] = c;
		i++;
	}
	return (result);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("%s\n", (char *)ft_memset(argv[1], 48, 4));
	}
	return (0);
}
