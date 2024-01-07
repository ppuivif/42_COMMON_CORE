#include <stddef.h>

int convert_digit(char c, int str_base)
{
    if (str_base <= 10)
    { 
        if (c >= '0' && c <= '9' && (c - 48) < str_base)
            return(c - 48);
    }
    else if (str_base > 10 && str_base <= 16)
    { 
        if (c >= '0' && c <= '9' && (c - 48) < str_base)
            return (c - 48);
        else if (c >= 'a' && c <= 'f' && (c - 97 + 10) < str_base)
            return(c - 87);
        else if (c >= 'A' && c <= 'F' && (c - 65 + 10) < str_base)
            return (c - 65);
    }
    return (-1);
}

int ft_atoi_base(const char *str, int str_base)
{
    int i;
    int nbr;
    int sign;

    i = 0;
    nbr = 0;
    sign = 1;
    if (!str || str_base <= 0 || str_base > 16)
        return (-1);
    while (str[i] && (str[i] == 45 || str[i] == 43))
    {
        if (str[i] == 45)
            sign *= -1;
        i++;
    }
    while (convert_digit(str[i], str_base) >= 0)
    {
        nbr = nbr * str_base + convert_digit(str[i], str_base);
        i++;
    }
    return (nbr * sign);
}

#include <stdio.h>

int main(void)
{
    printf("%d\n", ft_atoi_base("030", 3));
    return (0);
}