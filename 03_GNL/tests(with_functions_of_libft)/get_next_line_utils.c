#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str && str[len])
		len++;
	return(len);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str && str[i])// gerer str == NULL ?
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if (str[i] == (char)c)// cas ou c == '\0'
		return (&str[i]);
	return (NULL);
}

char	*ft_strtrim(char *str, int c)
{
	int	i;
	int	len;
	char *dest;

	if (!str)
		return (NULL);
	i = 0;
	len = ft_strlen(str) - ft_strlen(ft_strchr(str, c));
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (i <= len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = 0;
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof (char));
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
	str[i + j] = 0;
	free(s1);
	s1 = NULL;
	return (str);
}

void free_all(void *s1, void *s2)
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

