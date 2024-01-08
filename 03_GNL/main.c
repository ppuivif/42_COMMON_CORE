#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int fd;
	char	*tab;
	int	i = 0;

	fd = open ("document", O_RDWR);//O_RDONLY
//	if (open = -1) condition a inclure
	
	while (i < 3)
	{
		tab = get_next_line(fd);
		printf("%s", tab);
		free(tab);
		i++;
	}
	close (fd);
//close permet de fermer l'acces au fichier prealablement open
	return (0);
}
