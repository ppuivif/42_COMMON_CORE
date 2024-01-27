#include <stdio.h>
#include <stdlib.h>

int pgcd(unsigned int i1, unsigned int i2)
{
	unsigned int dc;

	if (i1 == 0 || i2 == 0)
		return (0);
	if (i1 == i2)
		return (i1);
	if (i1 > i2)
		dc = i2;
	else
		dc = i1;
	while (dc > 0)
	{
		if ((i1 % dc == 0) && (i2 % dc == 0))
			return (dc);
		dc--;
	}
	return (1);
}


int main(int argc, char **argv)
{
	int dc = pgcd(atoi(argv[1]), atoi(argv[2]));
	if (argc == 3 && dc != 0)
		printf("%d", dc);
	printf("\n");
	return (0);
}