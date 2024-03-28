
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h> // to delete


int	main()
{
	int	fd;

	fd = open("outfile.txt", O_WRONLY);
	dup2(fd, STDOUT_FILENO);
	close (fd);
	printf("test\n");
}