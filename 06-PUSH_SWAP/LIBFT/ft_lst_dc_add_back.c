#include "libft.h"

void	ft_lst_dc_add_back(t_list **list, t_list *new_element)
{
	t_list *last_element;

	if(!new_element)
		return;
	if (!*list)
	{
		*list = new_element;
		return ;
	}
	else
	{
		last_element = ft_lst_dc_last(*list);
		last_element->next = new_element;
		new_element->previous = last_element;
		new_element->next = *list;
		(*list)->previous = new_element;
	}
}
