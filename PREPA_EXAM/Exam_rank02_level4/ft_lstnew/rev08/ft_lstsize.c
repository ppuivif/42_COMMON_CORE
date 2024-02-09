#include "ft_list.h"

int	ft_lstsize(t_list *list)
{
	int	nb_element;

	nb_element = 0;
	while (list)
	{
		list = list->next;
		nb_element++;
	}
	return (nb_element);
}