#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *str;
    char *str2;
    

    str = malloc(5*sizeof(char));
    str = strcpy(str, "abcd");    
    printf("after malloc & initialization : \n%s\n", str);
    printf("%p\n\n", str);
    free(str);
    printf("after free : \n%s\n", str);
    printf("%p\n\n", str);
    str = NULL;//so !str
    //printf("%s\n", str);
    printf("after NULL initialization : \n%p\n\n", str);
    str2 = malloc(5*sizeof(char));
    str2 = strcpy(str2, "zzzz");
    str = malloc(5*sizeof(char));
    str = strcpy(str, "efgh");    
    printf("after new malloc and new initialization : \n%s\n", str);
    printf("%p\n", str);
    return (0);
}
