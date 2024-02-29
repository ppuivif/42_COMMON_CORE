#include "libft.h"

t_list	*ft_lst_dc_new(void *content, void *position)
{
	t_list *new_element;

	new_element = malloc(sizeof(t_list));
	if(!new_element)
		return (NULL);
	else
	{
		new_element->content = content;
		new_element->position = position;
		new_element->next = NULL;
		new_element->previous = NULL;
	}
	return (new_element);
}