#include <stddef.h>


void *ft_memset(void *s, int c, size_t n)
{
    size_t           i;
    unsigned char   *tmp;
    
    tmp = s;
    i = 0;
    while (s && i < n)
    {
        tmp[i] = c;
        i++;
    }
    return (s);
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc == 4)
	{
		printf("real function return : \t%s\n", (char *)memset(argv[1], (argv[2][0]), atoi(argv[3])));
        printf("ft function return : \t%s\n", (char *)ft_memset(argv[1], (argv[2][0]), atoi(argv[3])));
	}
}