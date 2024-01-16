#include <stdio.h>
#include "get_next_line_rev01.h"

/*int	main()
{
//	int fd;
	char *s = "abcdefghij";
	int index = 0;
	char *str;
	char *line = "123\0";
	char *buf;
	
	str = ft_strdup(s);
	//line = NULL;
//	fd = open("text", O_RDONLY);	return (str);

	//buf = ft_strchr(str, 'e', &index);
	
	buf = str;
	if (ft_strchr(buf, 'e', &index) != 0)
			{
				line = ft_strjoin(line, ft_substr(buf, 0, (ft_strlen(buf) - ft_strlen(ft_strchr(buf, 'e', &index) + 1))));
				buf = ft_substr(buf, index + 1, (ft_strlen(ft_strchr(buf, 'e', &index)) - 1));
			}
	printf("str %s\n", str);
	printf("buf %s\n", buf);
	printf("line %s\n", line);
	free(str);
	free(buf);
	free(line);

//	close (fd);
	return(0);
}*/

int main()
{
	int	fd;
	char *tab;
	int i;

	i = 0;
    fd = open("text", O_RDONLY);

	while (i < 3)
	{
		tab = get_next_line(fd);
		printf("%s", tab);
		free(tab);
		i++;
	}
    close (fd);
	return (0);
}