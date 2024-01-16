#include <stdio.h>

int	main()
{
	char *str1 = "qwert";
	char	str2[] = "qwert";
	printf("sizeof doesn't work with *str : %ld\n", sizeof(str1));
	printf("sizeof work with str [] :  %ld\nand include 0 at the end of the string\n", sizeof(str2));
	return (0);
}
