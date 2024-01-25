#include "so_long.h"

char **read_map(fd)
{
	int	i;
	char **tab;

	i = 0;
	while (i < 4)
	{
		tab[i] = get_next_line(fd);
		if (tab[i] = NULL)
			return (NULL);
		i++;
	}
	return (tab);
	//free (tab);
	close (fd);
	return (0);
}
