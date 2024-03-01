#include "libft.h"

size_t	ft_lst_dc_size(t_element *head)
{
	size_t	len;
	t_element	*last_element;

	len = 1;
	if (!head)
		return (0);
	last_element = ft_lst_dc_last(head);
	if (last_element == head)
		return (1);
	while (head != last_element)
	{
		head = head->next;
		len++;
	}
	return(len);
}