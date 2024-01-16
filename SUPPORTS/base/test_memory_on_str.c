#include <stdio.h>
#include <stdlib.h>

int	main()
{
//	char	*str;
	char	str[] = "abcdef";

//	str = "abcdef";
	printf("str : %s\n", str);
	printf("%p\n", str);
//	free(str);
//	printf(" after free str : %s\n", str);
//	printf("%p\n", str);
	str = NULL;
	printf("after str = NULL : %s\n", str);
	printf("%p\n", str);
	return (0);
}
