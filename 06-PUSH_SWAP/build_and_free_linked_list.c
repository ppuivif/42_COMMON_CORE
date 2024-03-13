#include "push_swap.h"

void	build_linked_list(int *int_arr, t_list	**list)
{
	int			i;
	t_element	*new_element;

	i = 0;
	while (i < (*list)->size)
	{
		new_element = ft_lst_dc_new(int_arr[i]);
		new_element->position = i + 1;
		ft_lst_dc_add_back(&(*list)->head, new_element);
		i++;
	}
}

void	index_stack(t_element **head)
{
	int i;
	int size;
	t_element	*element_to_examinate;
	t_element	*increased_element;

	i = 0;
	size = ft_lst_dc_size(*head);
	element_to_examinate = (*head);
	while (i < size)
	{
		increased_element = element_to_examinate->next;
		while (increased_element != (*head))
		{
			if (element_to_examinate->number > increased_element->number)
				element_to_examinate->index += 1;
			else
				increased_element->index += 1;		
			increased_element = increased_element->next;
		}
		i++;
		element_to_examinate = element_to_examinate->next;
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

