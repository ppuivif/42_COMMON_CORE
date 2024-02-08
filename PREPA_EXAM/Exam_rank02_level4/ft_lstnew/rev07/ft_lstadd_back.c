#include "ft_list.h"

void ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*ptr_last_element;
	
	if(!new)
		return;
	if(!list)
	{
		*list = new;
		return;
	}
	ptr_last_element = ft_lstlast(*list);
	ptr_last_element->next = new;
}