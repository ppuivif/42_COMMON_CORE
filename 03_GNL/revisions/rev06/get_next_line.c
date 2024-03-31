#include "get_next_line.h"

static int	get_lines(char **tmp, char **buf, char **line)
{
	int			start;
	char 		*tmp2;
	
	start = ft_get_strchr(*buf, '\n');
	if (!*buf)
	{
		*line = NULL;
		return (1);
	}
	if (start != -1)
	{
		tmp2 = ft_substr(*buf, 0, start + 1);
		*line = ft_get_strjoin(*line, tmp2);
		free(tmp2);
		tmp2 = NULL;
		*buf = ft_get_substr(*buf, start + 1, ft_strlen(*buf) - (start - 1));
		if (**buf == '\0')
		{
			free(*buf);
			*buf = NULL;
		}
		free(*tmp);
		*tmp = NULL;
		return (1);
	}
	else
		return (0);
}	

static void	end_of_file(char **tmp, char **buf, char **line)
{
		if (*buf)
		{
			if (get_lines(tmp, buf, line) == 1)
				return ;
			else
			{
				*line = ft_get_strjoin(*line, *buf);
				free(*tmp);
				*tmp = NULL;
				free(*buf);
				*buf = NULL;
				return ;
			}
		}
		else
		{
			free(*tmp);
			*tmp = NULL;
			free(*buf);
			*buf = NULL;
			*line = NULL;
			return ;
		}
}	

char	*get_next_line(int fd)
{
	int			nb_read_bytes;
	char		*tmp;
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	nb_read_bytes = 0;
	line = NULL;
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
			return (NULL);
		}
		if (nb_read_bytes == 0)
		{
			end_of_file(&tmp, &buf, &line);
			return (line);
		}
		buf = ft_get_strjoin(buf, tmp);
		free(tmp);
		tmp = NULL;
		if (get_lines(&tmp, &buf, &line) == 1)
			return (line);
	}
}


