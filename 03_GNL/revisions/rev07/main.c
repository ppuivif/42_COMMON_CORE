#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int fd;
	char	*tab;
	int	i = 0;

	fd = open("multiple_nlx5", O_RDWR);
	
	while (i < 4)
	{
		tab = get_next_line(fd);
		printf("%s", tab);
		free(tab);
		i++;
	}
	close (fd);
	return (0);
}
