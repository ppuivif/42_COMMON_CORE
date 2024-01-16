#ifndef GET_NEXT_LINE_REV02_H
# define GET_NEXT_LINE_REV02_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char	*get_next_line(int fd);
void	free_all(char *s1, char *s2);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*begin_new_line(char *s1);
char	*close_current_line(char *s1);
int		find_line_return(char *s);

#endif