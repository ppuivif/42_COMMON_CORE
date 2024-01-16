#ifndef GET_NEXT_LINE_REV01_H
# define GET_NEXT_LINE_REV01_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int		main();
size_t	ft_strlen(const char *str);
char    *ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *str, int c, int *index);
void	ft_strdupl(char **s);
char	*ft_strdup(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char    *get_next_line(int fd);
void	free_all(char *s1, char *s2);
char	*eof(char *buf, char *line, char *tmp);
char	*begin_new_line(char *s1);
char	*close_current_line(char *s1);
int		find_line_return(char *s);
void	*ft_calloc(size_t nmemb, size_t size);

#endif