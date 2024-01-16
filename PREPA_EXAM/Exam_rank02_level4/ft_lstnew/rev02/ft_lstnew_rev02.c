#include "ft_list.h"

t_list	*ft_lstnew(int content)
{
	t_list *list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}
