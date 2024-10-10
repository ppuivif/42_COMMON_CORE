#include <unistd.h>
#include <stdio.h>
#include <string.h>


size_t  ft_strlen(const char *str)
{
    size_t  len;

    len = 0;
    while (str && *str)
    {
        str++;
        len++;
    }
    return (len);
}

int main(int argc, char **argv)
{
    if (argc == 2)
		printf("real function return : %ld\n", strlen(argv[1]));
    if (argc == 3)
	{
		printf("ft_function return : %ld\n", ft_strlen(argv[1]));
		printf("string : %s\n", (argv[1]));
	}
}