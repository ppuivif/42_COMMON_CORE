#include "push_swap.h"

void	build_linked_list(char *int_arr, int count)
{
	t_list	*list;
	t_list	*new_element;
	void	*content;
	int		i;

	i = 0;

	while (i < count)
	{
		content = int_arr[i];
		new_element = ft_lst_dc_new(content, i);
		lst_dc_add_back(new_element);
	}




}

