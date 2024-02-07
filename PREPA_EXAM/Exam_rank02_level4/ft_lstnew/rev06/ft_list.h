#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>

typedef struct s_list
{
	void *content;
	struct s_list *next;
}	t_list;

t_list *ft_lstnew(void *content);
t_list *ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);

#endif