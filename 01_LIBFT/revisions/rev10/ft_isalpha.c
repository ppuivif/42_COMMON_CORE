#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int ft_isalpha(int c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    else
        return (0);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
//        printf("real function return : %d\n", isalpha(atoi(argv[1])));
        printf("real function return : %d\n", isalpha(argv[1][0]));
    }
    if (argc == 3)
    {
//        printf("function return : %d\n", ft_isalpha(atoi(argv[1])));
        printf("function return : %d\n", ft_isalpha((argv[1][0])));
    }
    return (0);
}