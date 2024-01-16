#include "get_next_line_rev02.h"

char	*get_next_line(int fd)
{
	int	nb_read_bytes;
	char *tmp;
	static char *buf;
	char *line;

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
				return(line);
			}
			else
			{
				free_all(tmp, buf);
				return(NULL);
			}
		}
		buf = ft_strjoin(buf, tmp);
		free_all(tmp, NULL);
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
