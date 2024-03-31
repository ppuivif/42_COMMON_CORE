#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	j;
	size_t	i;

	j = nmemb * size;
	i = 0;
	if (!size || !nmemb)
		return (malloc(1));
	if (j > 4294967295 || (size > 65535 && nmemb > 65535))
//	if (j > ULONG_MAX || (size > USHRT_MAX || nmemb > USHRT_MAX))
		return (NULL);
	str = malloc(j);
	if (!str)
		return (NULL);
	while (i < j)
	{
		str[i] = '\0';
		i++;
	}
	return ((void *) str);
}

char	*ft_get_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof (char));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	free(s1);
	s1 = NULL;
	return (str);
}

int	ft_get_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (i);
		i++;
	}
	if (str[i] == (char)c)
		return (i);
	return (-1);
}

#include <stdio.h>

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*result;
	int		i;


	i = 0;
	if (!str)
		return (NULL);
	if (start > (unsigned int)ft_strlen (str))
		len = 0;
	if (len > ft_strlen(&str[start]))
		len = ft_strlen(&str[start]);
	result = ft_calloc((len + 1), sizeof(char));
	if (!result)
		return (NULL);
	while (i < (int)len && str[start])
	{
		result[i] = str[start];
		i++;
		start++;
	}
	return (result);
}

char	*ft_get_substr(char *str, unsigned int start, size_t len)
{
	char	*result;
	int		i;


	i = 0;
	if (!str)
		return (NULL);
	if (start > (unsigned int)ft_strlen (str))
		len = 0;
	if (len > ft_strlen(&str[start]))
		len = ft_strlen(&str[start]);
	result = ft_calloc((len + 1), sizeof(char));
	if (!result)
		return (NULL);
	while (i < (int)len && str[start])
	{
		result[i] = str[start];
		i++;
		start++;
	}
	free(str);
	str = NULL;
	return (result);
}

