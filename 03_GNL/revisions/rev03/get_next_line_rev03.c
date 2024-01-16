#include "get_next_line_rev03.h"

char	*get_next_line(int fd);
{
	char *tmp;
	static char *buf;	
	char *line;
	int nb_read_bytes;


	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	nb_read_bytes = 0;
	while (1)
	{
		tmp = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (!tmp)
			return (NULL);
		nb_read_bytes = read(fd, tmp, BUFFER_SIZE);
		if (nb_read_bytes == -1)
			return (NULL);
		if (nb_read_bytes == 0)
		{
			if (buf)
			{
				if (find_line_return(buf) > 0)
				{
					line = close_current_line(buf);
					buf = begin_new_line(buf);
					free_all(tmp, NULL);
					return (line);
				}
				line = ft_strjoin(line, buf);
				free_all(tmp, buf);
				return (line);
			}
			free_all(tmp, buf);
			return (NULL);
		}
		buf = ft_strjoin(buf, tmp);
		free_all(tmp, NULL);
		tmp = NULL;
		if (buf == NULL)
			return (NULL); 
		if (find_line_return(buf) > 0)
		{
			line = close_current_line(buf);
			buf = begin_new_line(buf);
			return (line);
		}
	}
}

