#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    int i;

    i = 0;
    if(!s)
        return (0);
    while(s[i])
    {
        i++;
    }
    return (i);
}

static void    ft_join(char *buffer, char **s)
{ 
    char *ref;
    
    if (buffer[0] == '\0')
    {
        *s = NULL;
        return ;
    }
    ref = ft_strchr(buffer, '\n');
    if (ref)
    {
        *s = ft_strnjoin(*s, buffer, ref - buffer + 1);
        ft_strlcpy(buffer, ref + 1, BUFFER_SIZE);
    }
    else
        *s = ft_strnjoin(*s, buffer, BUFFER_SIZE);
}

char    *get_line(int fd)
{
    static char    buffer[BUFFER_SIZE + 1];
    int            bytes;
    char        *s;

    bytes = 1;
    s = NULL;
    ft_join(buffer, &s);
    while (bytes > 0 && !ft_strchr(s, '\n'))
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        if (bytes < BUFFER_SIZE)
            buffer[bytes] = '\0';
        if (bytes > 0)
            ft_join(buffer, &s);
    }
    if (s && s[0] == '\0')
        free(s);
    return (s);
}

char *get_next_line(int fd) 
{
    char *arr;
   
    if (fd < 0 || fd > FD_MAX)
        return (NULL);
    arr = get_line(fd);
    return (arr);
}
