#include "ft_list.h"

t_list	*ft_lstlast(t_list *list)
{
	t_list *last_element;

	if(!list)
		return (NULL);
	last_element = list;
	while (last_element->next)
		last_element = last_element->next;
	return(last_element);
}