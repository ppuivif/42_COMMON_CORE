#include "get_next_line.h"
#include <stdio.h>

int	main()
{
	int i;
	int	fd;
	char *str;

	i = 0;
	fd = open("text.txt", O_RDONLY);
	while (i < 2)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		i++;
	}
	close (fd);
	return (0);
}