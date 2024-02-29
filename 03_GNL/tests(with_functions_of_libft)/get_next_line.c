#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char 		*tmp1;
	char 		*tmp2;
	static char *buf;
	char 		*line;
	int			nb_read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	nb_read_bytes = 0;
	while (1)
	{
		tmp1 = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!tmp1)
			return (NULL);
		tmp1[BUFFER_SIZE] = 0;
		nb_read_bytes = read(fd, tmp1, BUFFER_SIZE);
		if (nb_read_bytes == -1)
		{
			free (tmp1);
			tmp1 = NULL;
			return (NULL);
		}
		if (nb_read_bytes == 0)
		{
			if (!buf)
			{
				free_all(buf, tmp1);
				return (NULL);
			}
			else
			{
				if (ft_strchr(buf, '\n') == NULL)
				{
					line = ft_strjoin(line, buf);
					free_all(buf, tmp1);
					return (line);
				}
				else
				{
					tmp2 = ft_strtrim(buf, '\n');
					line = ft_strjoin(line, tmp2);
					free_all(tmp2, tmp1);
					buf = ft_strchr(buf, '\n');
					return (line);
				}
			}	 
		}
		buf = ft_strjoin(buf, tmp1);
		free(tmp1);
		tmp1 = NULL;
		if (ft_strchr(buf, '\n') != NULL)
		{
			tmp2 = ft_strtrim(buf, '\n');
			line = ft_strjoin(line, tmp2);
			free(tmp2);
			tmp2 = NULL;
			buf = ft_strchr(buf, '\n');
			return (line);
		}
	}
}
