#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>

typedef struct s_list
{
	void 			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *list);
void	ft_lstadd_front(t_list **list, t_list *new_element);
void	ft_lstadd_back(t_list **list, t_list *new_element);
size_t	ft_lstsize(t_list *list);
void	ft_lstdelone(t_list *list, void (*del)(void *));
void	del(void *element_to_del);


#endif