#include <stdio.h>
#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <fcntl.h>

/*int	main(void)
{
	int fd;
	char	*tab;
	int	i = 0;

//	fd = 0;
	fd = open("document", O_RDWR);//O_RDONLY
//	if (open renvoie -1) erreur d'ouverture
	
	while (i < 4)
	{
		tab = get_next_line(fd);
		printf("%s", tab);
		free(tab);
		i++;
	}
	close (fd);
//close permet de fermer l'acces au fichier prealablement open
//permet d'eviter de laisser un acces ouvert a un fichier
	return (0);
}*/

int	main(void)
{
	int fd1;
	char	*tab1;
	int fd2;
	char	*tab2;
	int	i = 0;

	fd1 = open("document", O_RDWR);
	fd2 = open("document(full)", O_RDWR);
	
	while (i < 3)
	{
		tab1 = get_next_line(fd1);
		printf("%s", tab1);
		free(tab1);
		tab2 = get_next_line(fd2);
		printf("%s", tab2);
		free(tab2);
		i++;
	}
	close (fd1);
	close (fd2);
	return (0);
}

