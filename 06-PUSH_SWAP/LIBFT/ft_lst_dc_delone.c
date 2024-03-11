#include "libft.h"

void	ft_lst_dc_delone (t_element **head, t_element *element_to_del)
{
	t_element	*element_to_search;
	
	if (!element_to_del || !head)
		return;
	if (*head == element_to_del)
	{	
		if (!element_to_del->next)
			*head = NULL;		
		else
			*head = element_to_del->next;
	}
	element_to_search = *head;
	while (element_to_search->next != element_to_del)
		element_to_search = element_to_search->next;
	element_to_search->next = element_to_search->next->next;
	element_to_search->next->previous = element_to_search;
	element_to_del->number = 0;
	free(element_to_del);
}

