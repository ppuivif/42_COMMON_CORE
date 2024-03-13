#include "push_swap.h"

void	build_linked_list(int *int_arr, t_list	**list)
{
	int			i;
	t_element	*new_element;

	i = 0;
	while (i < (*list)->size)
	{
		new_element = ft_lst_dc_new(int_arr[i]);
		ft_lst_dc_add_back(&(*list)->head, new_element);
		i++;
	}
}

void	free_linked_list(t_list **list)
{
	int size;

	size = ft_lst_dc_size((*list)->head);

	while (size > 1)
	{
		ft_lst_dc_delone(&(*list)->head, (*list)->head);
		size--;
	}
	free((*list)->head);
	free(*list);
}
