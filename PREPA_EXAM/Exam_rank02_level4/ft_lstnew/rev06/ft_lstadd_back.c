#include "ft_list.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *ptr_last_element;

	if (!new)
		return;
	if (!*lst)
	{
		*lst = new;
		return;
	}
	ptr_last_element = ft_lstlast(*lst);
	ptr_last_element->next = new;
}