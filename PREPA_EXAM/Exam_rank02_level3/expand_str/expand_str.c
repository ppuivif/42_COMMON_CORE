#include <unistd.h>

void    expand_str(char *str)
{
    int i;
    int flag;

    i = 0;
    flag = 0;
    while (str[i] && (str[i] == ' ' || str[i] == '\t'))
        i++;
    while (str[i])
    {
        if ((str[i] == ' ' || str[i] == '\t'))
            flag = 1;
        else
        {
            if (flag == 1)
                write(1, "---", 3);
            write(1, &str[i], 1);
            flag = 0;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        expand_str(argv[1]);
    write (1, "\n", 1);
    return (0);
}