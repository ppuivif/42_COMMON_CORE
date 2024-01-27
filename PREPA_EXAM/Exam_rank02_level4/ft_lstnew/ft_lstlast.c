#include "ft_list.h"

t_list *ft_lstlast(t_list *lst)
{
	t_list	*ptr_last_element;

	if(!lst)
		return (NULL);
	ptr_last_element = lst;
	while (ptr_last_element->next != NULL)
		ptr_last_element = ptr_last_element->next;
	return (ptr_last_element);
}
