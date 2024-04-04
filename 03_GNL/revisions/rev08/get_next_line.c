#include "get_next_line.h"

void ft_free_all(char *s1, char *s2)
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

static int	get_lines(char **buf, char **line)
{
	int start = 0;
	char *tmp2;

	if (!*buf)
	{
		*line = NULL;
		return (0);
	}
	start = ft_get_strchr(*buf, '\n');
	if (start != -1)
	{
		tmp2 = ft_substr(*buf, 0, start + 1);
		*line = ft_get_strjoin(*line, tmp2);
		free(tmp2);
		tmp2 = NULL;
//		ft_free_all(&tmp2, NULL);
		*buf = ft_get_substr(*buf, start + 1, ft_strlen(*buf) - (start - 1));
		if (**buf == '\0')
		{
			free (*buf);
			*buf = NULL;
//			ft_free_all(NULL, *buf);
		}
		return (0);
	}
	return (1);
}

static void	end_of_file(char **buf, char **line)
{
	if (!*buf)
	{
		*line = NULL;
		//ft_free_all(NULL, *buf);
		free(*buf);
		buf = NULL;
		return ;
	}
	if (get_lines(buf, line) == 0)
		return;
	else
	{
		*line = ft_get_strjoin(*line, *buf);
		free (*buf);
		*buf = NULL;
//		ft_free_all(NULL, *buf);
		return ;
	}
}

char *get_next_line(int fd)
{
	char *tmp;
	char *line = NULL;
	static char *buf;
	int nb_read_bytes = 0;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	while (1)
	{
		tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!tmp)
			return (NULL);
		nb_read_bytes = read(fd, tmp, BUFFER_SIZE);
		if (nb_read_bytes == -1)
		{
			free(tmp);
			tmp = NULL;
			free(buf);
			buf = NULL;
			//ft_free_all(tmp, buf);
			return (NULL);
		}
		if (nb_read_bytes == 0)
		{
			end_of_file(&buf, &line);
			free (tmp);
			tmp = NULL;
//			ft_free_all(tmp, NULL);
			return (line);
		}
		buf = ft_get_strjoin(buf, tmp);
		free (tmp);
		tmp = NULL;
//		ft_free_all(tmp, NULL);
		if (get_lines(&buf, &line) == 0)
			return (line);
	}
}
