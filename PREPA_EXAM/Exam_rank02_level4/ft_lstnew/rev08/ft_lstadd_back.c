#include "ft_list.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *last_element;
	
	if(!new)
		return;
	if(!*lst)
	{
		*lst = new;
		return;
	}
	last_element = ft_lstlast(*lst);
	last_element->next = new;
}