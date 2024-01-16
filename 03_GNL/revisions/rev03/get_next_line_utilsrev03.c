#include <limits.h>

void	free_all(char *s1, char *s2)
{
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	if (s2)
	{
		free(s2);
		s2 = NULL;
	}
}


void	*ft_calloc(size_t nmemb, size_t size)
{
	char *str;
	size_t i = 0;

	if (nmemb == 0 || size == 0)
		return (malloc (1));
	if (j > UINT_MAX || (nmemb > _POSIX_SSIZE_MAX && size > _POSIX_SSIZE_MAX))
		return (NULL);
	str = malloc(nmemb * size);
	if (!str)
		return (NULL);
	while (i < (nmemb * size))
	{
		str[i] = '\0';
		i++;
	}
	return ((void *)str);
}

size_t	ft_strlen(char *s)
{
	size_t i = 0;

	while (s && s[i])
		i++;
	return (i);
}

int	ft_find_line_return(char *str)
{
	int i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}
