#include "push_swap.h"

int	search_element_with_index(t_list	*list, int index)
{
	int			i;
	int			size;
	t_element	*tmp_element;

	i = 0;
	size = ft_lst_dc_size(list->head);
	tmp_element = list->head;
	while (i < size && size != 0)
	{
		if (tmp_element->index == index)
			return(tmp_element->new_position);
		tmp_element = tmp_element->next;
		i++;
	}
	return (0);
}

int	search_element_with_next_position(t_list *list, int next_position)
{
	int			i;
	int			size;
	t_element	*tmp_element;

	i = 0;
	size = ft_lst_dc_size(list->head);
	tmp_element = list->head;
	while (i < size && size != 0)
	{
		if (tmp_element->next_position == next_position)
			return(tmp_element->new_position);
		tmp_element = tmp_element->next;
		i++;
	}
	return (0);
}

int	search_max(t_list *list)
{
	int			i;
	int			size;
	int			max;
	t_element	*tmp_element;

	i = 0;
	size = ft_lst_dc_size(list->head);
	max = 0;
	tmp_element = list->head;
	while (i < size && size != 0)
	{
		max += tmp_element->new_position * tmp_element->index;
		tmp_element = tmp_element->next;
		i++;
	}
	return(max);
}

int	search_max_til_median(t_list *list)
{
	int			i;
	int			size;
	int			max;
	t_element	*tmp_element;

	i = 0;
	size = ft_lst_dc_size(list->head);
	max = 0;
	tmp_element = list->head;
	while (i < size / 2 && size != 0)
	{
		max += tmp_element->new_position * tmp_element->index;
		tmp_element = tmp_element->next;
		i++;
	}
	return(max);
}

/*int	search_best_sort(t_list *list)
{
	int			i;
	int			j;
	int			size;
	int			result;
	t_element	*tmp_element;

	j = 1;
	size = ft_lst_dc_size(list->head);
	ft_printf("mediane : %d\n", size / 2);
	result = 0;
	while (j <= (size / 2) && size != 0)
	{
		tmp_element = list->head;
		i = 0;
		while (i < size)
		{
			if (tmp_element->index == j)
				result += tmp_element->new_position;
			tmp_element = tmp_element->next;
			i++;
		}
		j++;
	}
	return(result);
}*/

int	combination(t_list *list, int index_begin, int index_end)
{
	int			i;
	int			size;
	int			result;
	t_element	*tmp_element;

	i = 0;
	size = ft_lst_dc_size(list->head);
	result = 0;
	tmp_element = list->head;
	while (i < size && size != 0)
	{
		if (tmp_element->index >= index_begin && tmp_element->index <= index_end)
				result += tmp_element->new_position * tmp_element->index;
		tmp_element = tmp_element->next;
		i++;
	}
	return(result);
	
	/*result = search_position((list), index_1) * index_1 +
		search_position((list), index_2) * index_2;
	return(result);*/
}

int	search_best_sort_index(t_list **src, t_list **dest, int index)//int to modify in void
{
	int	size_src;
	int	hits;//to delete

	size_src = ft_lst_dc_size((*src)->head);
	hits = 0;//to delete
	if (search_element_with_index((*src), index) <= size_src / 2)
	{
		while ((*src)->head->index != index)
		{
			rotate(&(*src)->head, 'a');
			update_new_position(&(*src)->head);
			hits++;//to delete
		}
		push(&(*src)->head, &(*dest)->head, 'b');
		update_new_position(&(*src)->head);
		hits++;//to delete
	}
	else
	{
		while ((*src)->head->index != index)
		{
			reverse_rotate(&(*src)->head, 'a');
			update_new_position(&(*src)->head);
			hits++;//to delete
		}
		push(&(*src)->head, &(*dest)->head, 'b');
		update_new_position(&(*src)->head);
		hits++;//to delete
	}
	return (hits);//to delete
}

int	search_best_sort_next_position(t_list **src, t_list **dest, int next_position)//int to modify in void
{
	int	size_src;
	int	hits;//to delete

	size_src = ft_lst_dc_size((*src)->head);
	hits = 0;//to delete
	if (search_element_with_next_position((*src), next_position) <= size_src / 2)
	{
		while ((*src)->head->next_position != next_position)
		{
			rotate(&(*src)->head, 'a');
			update_new_position(&(*src)->head);
			hits++;//to delete
		}
		push(&(*src)->head, &(*dest)->head, 'b');
		update_new_position(&(*src)->head);
		hits++;//to delete
	}
	else
	{
		while ((*src)->head->next_position != next_position)
		{
			reverse_rotate(&(*src)->head, 'a');
			update_new_position(&(*src)->head);
			hits++;//to delete
		}
		push(&(*src)->head, &(*dest)->head, 'b');
		update_new_position(&(*src)->head);
		hits++;//to delete
	}
	return (hits);//to delete
}

/*void	ft_sort_2a(t_list **src, t_list **dest)
{
		push(&(*src)->head, &(*dest)->head, 'b');
		push(&(*src)->head, &(*dest)->head, 'b');
}*/

/*void	ft_sort_2b(t_list **src, t_list **dest)
{
		push(&(*src)->head, &(*dest)->head, 'b');
		push(&(*src)->head, &(*dest)->head, 'b');
		swap(&(*dest)->head, 'b');
}*/

/*void	ft_sort_2b(t_list **src, t_list **dest)
{
		while ((*src)->head->index != 1)
			rotate(&(*src)->head, 'a');
		push(&(*src)->head, &(*dest)->head, 'b');
		while ((*src)->head->index != 2)
			rotate(&(*src)->head, 'a');
		push(&(*src)->head, &(*dest)->head, 'b');
}*/

/*int	ft_butterfly_ab(t_list	**src, t_list **dest)
{



	int	median_src;
//	int	median_dest;
	int hits;//to delete
	int	i;

	median_src = ft_lst_dc_size((*src)->head) / 2 + 1;
	hits = 0;//to delete
	i = 1;
	while (i < median_src / j)
	{
		while ((*src)->head->new_position != i)
		{
			rotate(&(*src)->head, 'a');
//			ft_lst_dc_print((*src)->head);
			hits++;//to delete
		}
		ft_printf("number : %d\n", (*src)->head->number);
		push(&(*src)->head, &(*dest)->head, 'b');
//		ft_lst_dc_print((*src)->head);
		hits++;//to delete
		while ((*src)->head->new_position != i + (median_src / j) - 1)
		{
			rotate(&(*src)->head, 'a');
//			ft_lst_dc_print((*src)->head);
			hits++;//to delete
		}
		push(&(*src)->head, &(*dest)->head, 'b');
//		ft_lst_dc_print((*src)->head);
//		ft_printf("number : %d\n", (*src)->head->number);
		hits++;//to delete
		if (&(*dest)->head->index < &(*dest)->head->next->index)
		{
			swap(&(*dest)->head, 'b');
			hits++;//to delete
		}
		i++;			
	}
	update_new_position(&(*src)->head);
	update_new_position(&(*dest)->head);
	return (hits);
}

int	ft_butterfly_ba(t_list	**src, t_list **dest, int j)
{
//	int	median_src;
	int	median_dest;
	int hits;//to delete
	int	i;

	median_dest = ft_lst_dc_size((*dest)->head) / 2 + 1;
	hits = 0;//to delete
	while (ft_lst_dc_size((*dest)->head))
	{
		i = median_dest / j;
		while (i > 0)
		{
			while ((*dest)->head->new_position != i)
			{
				rotate(&(*dest)->head, 'b');
//				ft_lst_dc_print((*src)->head);
				hits++;//to delete
			}
			ft_printf("number : %d\n", (*dest)->head->number);
			push(&(*dest)->head, &(*src)->head, 'a');
//			ft_lst_dc_print((*src)->head);
			hits++;//to delete
			while ((*dest)->head->new_position != i + (median_dest / j) - 1)
			{
				rotate(&(*dest)->head, 'b');
//				ft_lst_dc_print((*src)->head);
				hits++;//to delete
			}
			push(&(*dest)->head, &(*src)->head, 'a');
//			ft_lst_dc_print((*src)->head);
//			ft_printf("number : %d\n", (*src)->head->number);
			hits++;//to delete
			if (&(*src)->head->index > &(*src)->head->next->index)
			{
				swap(&(*src)->head, 'b');
				hits++;//to delete
			}
			i--;			
		}
		update_new_position(&(*src)->head);
		update_new_position(&(*dest)->head);
	}
	return (hits);
}*/

void	sort_step_1(t_list	**src, int i, int *next_position_1, int *next_position_2)
{
	int	median_src;
//	int	i;
	t_element	*element_to_find_1; 
	t_element	*element_to_find_2; 
	int index_1;
	int index_2;

	median_src = ft_lst_dc_size((*src)->head) / 2 + 1;
//	i = 1;
	index_1 = 1;
	index_2 = 1;
//	while (i < median_src / j)
//	{
		element_to_find_1 = (*src)->head; 
		element_to_find_2 = (*src)->head;
		
		while (element_to_find_1->new_position != i)
			element_to_find_1 = element_to_find_1->next;
		index_1 = element_to_find_1->index;
		ft_printf("index_1 : %d\n", index_1);
		while (element_to_find_2->new_position != i + median_src / j - 1)
			element_to_find_2 = element_to_find_2->next;
		index_2 = element_to_find_2->index;
		ft_printf("index_2 : %d\n", index_2);
		if (index_1 > index_2)
		{
			*next_position_1 = i + median_src / j - 1;
			*next_position_2 = i;
		}
		else
		{
			*next_position_1 = element_to_find_1->new_position;
			*next_position_2 = element_to_find_2->new_position;
		}
		ft_printf("next_position_1 : %d\n", element_to_find_1->next_position);
		ft_printf("next_position_2 : %d\n", element_to_find_2->next_position);
//		i++;			
//	}
}




