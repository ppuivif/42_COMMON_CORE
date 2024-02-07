#include "ft_list.h"

t_list	*ft_lstnew(void *this_content)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	t_list->content = this_content;
	t_list->next = NULL; 
	return (tmp);
}
