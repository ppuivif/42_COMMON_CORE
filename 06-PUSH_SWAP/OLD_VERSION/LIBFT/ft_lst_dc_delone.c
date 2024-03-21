#include "libft.h"

#include <stdio.h>

void	ft_lst_dc_delone (t_element **head, t_element *element_to_del)
{
	t_element	*element_to_search;
	int			size;

	size = ft_lst_dc_size(*head);
	if (!element_to_del || !head)
		return;
	if (*head == element_to_del)
	{	
		if (size == 1)
		{
			*head = NULL;
			free(element_to_del);
			return;
		}
		else if (size == 2)
		{
			*head = (*head)->next ;
			(*head)->next = NULL;
			(*head)->previous = NULL;
			free(element_to_del);
			return;
		}
		*head = element_to_del->next;
	}
	element_to_search = *head;
	while (element_to_search->next != element_to_del)
		element_to_search = element_to_search->next;
	element_to_search->next = element_to_search->next->next;
	element_to_search->next->previous = element_to_search;
	free(element_to_del);
}

