#include "get_next_line_rev01.h"

char    *get_next_line(int fd)
{
	char		*tmp;
	static char	*buf;
	char		*line;
	int			nb_read_bytes;
	int			index;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	nb_read_bytes = 0;
	index = 0;
	line = NULL;
	while (1)
	{
		tmp = malloc(BUFFER_SIZE + 1 * sizeof(char));
		if (!tmp)
			return (NULL);
		nb_read_bytes = read(fd, tmp, BUFFER_SIZE);
		tmp[nb_read_bytes] = 0;
		if (nb_read_bytes == -1)
		{
			free_all(tmp, buf);
			return (NULL);
		}
		if (nb_read_bytes == 0)
			line = eof(tmp, buf, line);
		buf = ft_strjoin(buf, tmp);
	//	free(tmp);
		tmp = NULL;
		if (ft_strchr(buf, '\n', &index) != 0)
		{
			line = ft_strjoin(line, ft_substr(buf, 0, (ft_strlen(buf) - ft_strlen(ft_strchr(buf, '\n', &index) + 1))));
			buf = ft_substr(buf, index + 1, (ft_strlen(ft_strchr(buf, '\n', &index) - 1)));
			return (line);
		}
	}
}

/*void	ft_save(char *s, char *b)
{
	int	j;

	j = 0;
	while (s[j])
	{
		b[j] = s[j];
		j++;
	}
	while (j < BUFFER_SIZE)
	{
		b[j] = 0;
		j++;
	}
}*/

