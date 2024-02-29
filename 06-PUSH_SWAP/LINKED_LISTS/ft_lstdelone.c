#include "ft_list.h"

void	ft_lstdelone(t_list *list, void (*del)(void *))
{
	if (!list || !del)
		return;
	del(list);
	free(list);
}

void	del(void *element_to_del)
{
	t_list *element;
	
	element = (t_list *)element_to_del;
	element->content = NULL;
}