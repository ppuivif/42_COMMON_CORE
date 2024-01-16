#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_rev04.h"

int main()
{
	int i = 0;
	int fd = 0;

	fd = open("document", O_RDONLY);
	char *tab = get_next_line(fd);
	while (i < 3)
	{	
		printf("%s", tab);
		free(tab);
		i++;
	}
	close (fd);
	return (0);
}