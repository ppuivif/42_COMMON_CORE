#include "ft_list.h"

void	ft_lstadd_front(t_list **list, t_list *new)
{
	if(!new)
		return;
/*	if(!*list)
	{
		*list = new;
		return;
	}*/
	new->next = *list;
	*list = new;
}