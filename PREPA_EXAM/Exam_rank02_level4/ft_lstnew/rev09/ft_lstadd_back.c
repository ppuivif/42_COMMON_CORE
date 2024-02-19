#include "ft_list.h"

void	ft_lstadd_back(t_list** list, t_list *new_element)
{
	t_list *last_element;
	if(!new_element)
		return;
	if(!*list)
	{
		*list = new_element;
		return;
	}
	last_element = ft_lstlast(*list);
	last_element->next = new_element;
}