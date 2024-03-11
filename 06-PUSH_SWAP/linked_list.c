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

