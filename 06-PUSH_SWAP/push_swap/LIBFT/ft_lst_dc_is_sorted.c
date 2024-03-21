#include "libft.h"

int	ft_lst_dc_is_sorted(t_element *head)
{
	size_t	len;

	len = ft_lst_dc_size(head);
	if (len < 2)
		return (0);
	while (len > 1)
	{
		if (head->number < head->next->number)
			head = head->next;
		else
			return (0);
		len--;
	}
	return (1);
}
