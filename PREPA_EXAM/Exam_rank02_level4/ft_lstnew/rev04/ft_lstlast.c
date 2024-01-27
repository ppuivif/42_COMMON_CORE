#include "ft_list.h"

t_list *ft_lstlast(t_list *lst)
{
	t_list	*last_element;

	if(!lst)
		return (NULL);
	last_element = lst;
	while (last_element->next != NULL)
		last_element = last_element->next;
	return (last_element);
}
