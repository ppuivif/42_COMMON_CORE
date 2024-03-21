#include "ft_lst.h"

t_element	*ft_lst_dc_new(void *content, void *position)
{
	t_element *new_element;

	new_element = malloc(sizeof(t_element));
	if(!new_element)
		return (NULL);
	else
	{
		new_element->number = content;
		new_element->position = position;
		new_element->next = NULL;
		new_element->previous = NULL;
	}
	return (new_element);
}
