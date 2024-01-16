#ifndef FT_LIST_REV03_H
# define FT_LIST_REV03_H

# include <stdlib.h>

typedef struct s_list
{
	int content;
	struct s_list *next;
}	t_list;

t_list	*ft_lstnew(int content);

#endif