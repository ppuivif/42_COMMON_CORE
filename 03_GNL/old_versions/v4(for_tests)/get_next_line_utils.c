/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:53:47 by ppuivif           #+#    #+#             */
/*   Updated: 2023/12/11 17:51:30 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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

int	ft_strlen(char *s)
{
	int	i;
	
	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char **s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;

	//str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof (char));
	str = malloc((ft_strlen(s1) + BUFFER_SIZE + 1) * sizeof (char));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (*s2 && s2[j])
	{
		str[i + j] = *s2[j];
		j++;
	}
	str[i + j] = 0;
	if (s1)
		free(s1);
	free(*s2);
	*s2 = NULL;
//	s1 = NULL;
	return (str);
}

int	find_line_return(char *s)
{
	int		i;

	if (!s)
		return(0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

void	new_function(char **line, char **buf)
{
	int len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	len = find_line_return(*buf);
	*line = ft_calloc((len + 1), sizeof(char));
	if (!*line)
		*line = NULL;
	else
	{
		while (*buf && *buf[i] && i < len)
		{
			*line[i] = *buf[i];
			i++;
		}
		if (*buf[i] == '\0')
		{
			free(*buf);
			*buf = NULL;
		}
		else
		{
			while (*buf[i])
				*buf[j++] = *buf[i++];
	//		*buf[j+1] = '\0';
		}
	}	
}

char	*begin_new_line(char *s1)
{
	char	*s2;
	int	len;
	int	i;
	int	j;

	len = ft_strlen(s1) - find_line_return(s1);
	if (len == 0)
	{
		free(s1);
//		s1 = NULL;
		return (NULL);
	}
//	s2 = ft_calloc(len + 1, sizeof(char));
	s2 = malloc((len + 1) * sizeof(char));
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
	s2[i] = 0;
	if (s1)
	{
		free(s1);
//		s1 = NULL;
	}
	return (s2);
}

char	*close_current_line(char *s1)
{
	char	*s2;
	int	len;
	int	i;

	len = find_line_return(s1);
//	s2 = ft_calloc((len + 1), sizeof(char));
	s2 = malloc((len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	i = 0;
	while (s1 && s1[i] && i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}

/*char *ft_substr(const char *str, unsigned int start, size_t len)
{
	size_t		i;
	size_t		j;
	char		*str;

	i = start;
	j = 0;
	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(&s[start])))
		len = ft_strlen(&s[start]);
	str = (char *)malloc((len + 1) * sizeof (char));
	if (str)
	{
		while (j < len && s[i] != '\0')
		{
			str[j] = s[i];
			j++;
			i++;
		}
		str[j] = '\0';
		return (str);
	}
	return (NULL);
}
char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	str = (char *)malloc(len + 1);
	if (str)
	{
		while (i <= len)
		{
			str[i] = s[i];
			i++;
		}
		return (str);
	}
	return (0);
}*/
