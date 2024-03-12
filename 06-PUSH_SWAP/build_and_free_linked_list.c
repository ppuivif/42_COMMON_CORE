#include "push_swap.h"

void	build_linked_list(int *int_arr, int count, t_element **head)
{
	int			i;
	t_element	*new_element;

	i = 0;
	while (i < count)
	{
		new_element = ft_lst_dc_new(int_arr[i]);
		ft_lst_dc_add_back(head, new_element);
		i++;
	}
}

void	free_linked_list(t_list **list)
{
	int count;
	t_element	*last_element;

	count = ft_lst_dc_size((*list)->head);
	if (count == 1)
	{
		free((*list)->head);
		count = 0;
	}
	if (count > 0)
	{
		last_element = ft_lst_dc_last((*list)->head);
		while (count > 0)
		{
			ft_lst_dc_delone(&(*list)->head, last_element->next);
			if (last_element != (*list)->head)
				last_element = last_element->previous;
			count--;
		}
	}
	free(*list);
}
