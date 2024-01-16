#include "get_next_line_rev01.h"

void	free_all(char *s1, char *s2)
{
	if (s1)
	{
		free (s1);
		s1 = NULL;
	}
	if (s2)
	{
		free (s2);
		s2 = NULL;
	}
}

size_t	ft_strlen(const char *str)
{
    size_t i;

    i = 0;
	if (!str)
		return (0);
    while (str[i])
        i++;
    return (i);
}

char    *ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

    i = 0;
	j = 0;
//	if (!s1 || !s2)
//		return (NULL);
    str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
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
//	free(s1);
	free(s2);
	return(str);
}

char	*ft_strchr(const char *str, int c, int *index)
{
//	int	i;
//	i = 0;

	*index = 0;
	if (!str)
		return (NULL);
	while (str[*index])
	{
		if (str[*index] == (char)c)
			return ((char *)&str[*index]);
		*index = *index + 1;
	}
	if (str[*index] == (char)c)
			return ((char *)&str[*index]);
	return (NULL);
}

void ft_strdupl(char **s)
{
	int i;
	size_t len;
	char *str;

	if (!(*s))
		return ;
	i = 0;
	len = ft_strlen(*s);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return ;
	while (s[0][i] && i < (int)len)
	{
		str[i] = s[0][i];
		i++;
	}
	str[i] = '\0';
	free(s[0]);
	//*s = NULL;//a priori pas utile car realloc dans la ligne suivante
	*s = str;
}

char*	ft_strdup(char *s)
{
	int i;
	size_t len;
	char *str;

	if (!(s))
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i] && i < (int)len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!(s))
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	str = malloc((len + 1) * sizeof(char));
	if (str)
	{
		while (i < (unsigned int)len)
		{
			str[i] = s[start + i];
			i++;
		}
		str[i] = 0;
		return (str);
		//free (*s);
		//*s = NULL;
	}
	return (NULL);
}

char	*eof(char *buf, char *line, char *tmp)
{
	if (buf)
	{
		if (find_line_return(buf) > 0)
		{
			line = close_current_line(buf);
			buf = begin_new_line(buf);
			free(tmp);
			tmp = NULL;
			return (line);
		}
		line = ft_strjoin(line, buf);
		free(buf);
		buf = NULL;
		free(tmp);
		tmp = NULL;
		return (line);
	}
	else
	{
		free(buf);
		buf = NULL;
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
}

char	*begin_new_line(char *s1)
{
	char	*s2;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(s1) - find_line_return(s1);
	if (len == 0)
	{
		free(s1);
		return (NULL);
	}
	s2 = ft_calloc(len + 1, sizeof(char));
	if (!s2)
		return (NULL);
	i = 0;
	j = find_line_return(s1);
	while (s1 && s1[j])
	{
		s2[i] = s1[j];
		i++;
		j++;
	}
	if (s1)
		free(s1);
	return (s2);
}

char	*close_current_line(char *s1)
{
	char	*s2;
	int		len;
	int		i;

	len = find_line_return(s1);
	s2 = ft_calloc((len + 1), sizeof(char));
	if (!s2)
		return (NULL);
	i = 0;
	while (s1 && s1[i] && i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

int	find_line_return(char *s)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
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