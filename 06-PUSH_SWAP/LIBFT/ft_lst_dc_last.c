#include "libft.h"

t_list	*ft_lst_dc_last(t_list *list)
{
	t_list	*last_element;

	if (!list)
		return (NULL);
	if (list->previous)
		last_element = list->previous;
	else
		last_element = list;
	return (last_element);
}