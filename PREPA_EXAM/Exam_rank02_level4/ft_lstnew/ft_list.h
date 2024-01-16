#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>

typedef struct  s_list
{
	int			content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);

#endif