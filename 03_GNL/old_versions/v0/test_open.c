#include "get_next_line.h"
#include <stdio.h> 

int main()
{
	int fd;
	fd = open("test.txt", O_RDONLY);
	static char *buf;
	read(fd, buf, 5);
	printf("%s",buf);
	close(fd);
}
