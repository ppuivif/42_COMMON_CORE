#include "ft_lst.h"

t_element	*ft_lst_dc_last(t_element *head)
{
	t_element	*last_element;

	if (!head)
		return (NULL);
	if (!head->previous)
		last_element = head;
	else
		last_element = head->previous;
	return (last_element);
}
