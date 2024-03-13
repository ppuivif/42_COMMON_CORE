#include "libft.h"
t_element	*ft_lst_dc_new(int content)
{
	t_element *new_element;

	new_element = malloc(sizeof(t_element));
	if(!new_element)
		return (NULL);
	else
	{
		new_element->number = content;
		new_element->index = 0;
		new_element->next = NULL;
		new_element->previous = NULL;
	}
	return (new_element);
}