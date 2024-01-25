#include "so_long.h"
#include <stdlib.h>

int	main()
{
	int i;
	int fd;
	char **tab;

	i = 0;
	fd = open("map.ber", O_RDONLY);
	tab = read_map(fd);
	while (tab[i])
	{
		printf("%s", tab[i]);
		i++;
	}
	return (0);
}