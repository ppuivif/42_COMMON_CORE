#include <stdio.h>
#include "get_next_line_rev02.h"

int	main()
{
	char *tab;
	int fd1;
	int i;

	fd1 = open("document", O_RDONLY);
	i = 0;

	while (i < 2)
	{
		tab = get_next_line(fd1);
		printf("%s", tab);
		free(tab);
		i++;
	}
	close (fd1);
	return (0);
}