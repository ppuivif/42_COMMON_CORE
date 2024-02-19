#include "ft_list.h"

void	ft_lstadd_front(t_list **list, t_list *new_element)
{
	if (!new_element)
		return;
	new_element->next = *list;
	*list = new_element;
}