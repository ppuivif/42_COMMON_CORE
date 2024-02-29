#include "libft.h"

size_t	ft_lst_dc_size(t_list *list)
{
	size_t	len;
	t_list	*last_element;

	len = 0;
	if (!list)
		return (0);
	last_element = ft_lst_dc_last(list);
	if (last_element == list)
		return (1);
	while (list->next != last_element)
	{
		list = list->next;
		len++;
	}
	return(len + 2);
}