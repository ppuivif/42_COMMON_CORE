#include "push_swap.h"

int	search_new_position_element_with_index(t_list	*list, int index)
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

int	reverse_search_new_position_element_with_index(t_list	*list, int index)
{
	int			i;
	int			size;
	t_element	*tmp_element;

	size = ft_lst_dc_size(list->head);
	i = size;
	tmp_element = list->head;
	while (i > 0 && size != 0)
	{
		if (tmp_element->index == index)
			return(tmp_element->new_position);
		tmp_element = tmp_element->previous;
		i--;
	}
	return (0);
}

int	search_index_element_with_new_position(t_list *list, int new_position)
{
	int			i;
	int			size;
	t_element	*tmp_element;

	i = 0;
	size = ft_lst_dc_size(list->head);
	tmp_element = list->head;
	while (i < size && size != 0)
	{
		if (tmp_element->new_position == new_position)
			return(tmp_element->index);
		tmp_element = tmp_element->next;
		i++;
	}
	return (0);
}

int	search_index_element_with_next_position(t_list *list, int next_position)
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
			return(tmp_element->index);
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
	if (search_new_position_element_with_index((*src), index) <= size_src / 2)
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

int	search_best_sort_next_position_ab(t_list **src, t_list **dest, int next_position)//int to modify in void
{
	int	size_src;
	int	hits;//to delete

	size_src = ft_lst_dc_size((*src)->head);
	hits = 0;//to delete
	if (search_index_element_with_next_position((*src), next_position) <= size_src / 2)
	{
		while ((*src)->head->next_position != next_position)
		{
			rotate(&(*src)->head, 'a');
//			update_new_position(&(*src)->head);
			hits++;//to delete
		}
		push(&(*src)->head, &(*dest)->head, 'b');
//		update_new_position(&(*src)->head);
		hits++;//to delete
	}
	else
	{
		while ((*src)->head->next_position != next_position)
		{
			reverse_rotate(&(*src)->head, 'a');
//			update_new_position(&(*src)->head);
			hits++;//to delete
		}
		push(&(*src)->head, &(*dest)->head, 'b');
//		update_new_position(&(*src)->head);
		hits++;//to delete
	}
	return (hits);//to delete
}

int	search_best_sort_next_position_ba(t_list **src, t_list **dest, int next_position)//int to modify in void
{
	int	size_dest;
	int	hits;//to delete

	size_dest = ft_lst_dc_size((*dest)->head);
	hits = 0;//to delete
	if (search_index_element_with_next_position((*dest), next_position) <= size_dest / 2)
	{
		while ((*dest)->head->next_position != next_position)
		{
			rotate(&(*dest)->head, 'b');
//			update_new_position(&(*src)->head);
			hits++;//to delete
		}
		push(&(*dest)->head, &(*src)->head, 'a');
//		update_new_position(&(*src)->head);
		hits++;//to delete
	}
	else
	{
		while ((*dest)->head->next_position != next_position)
		{
			reverse_rotate(&(*dest)->head, 'b');
//			update_new_position(&(*src)->head);
			hits++;//to delete
		}
		push(&(*dest)->head, &(*src)->head, 'a');
//		update_new_position(&(*src)->head);
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
	

void	sort_step_ab(t_list **src, int j, int i)
{
	int	median_src;
//	int	i;
	t_element	*element_to_find;
	int index_1;
	int index_2;

	median_src = ft_lst_dc_size((*src)->head) / 2;
//	i = 1;
	index_1 = 1;
	index_2 = 1;
//	while (i <= median_src / j)
//	{
		index_1 = search_index_element_with_new_position((*src), i);
		ft_printf("index_1 : %d\n", index_1);
		index_2 = search_index_element_with_new_position((*src), i + median_src / j);
		ft_printf("index_2 : %d\n", index_2);
		element_to_find = (*src)->head; 
		while (element_to_find->new_position != i)
			element_to_find = element_to_find->next;
		if (index_1 > index_2)
			element_to_find->next_position = i + median_src / j;
		else
			element_to_find->next_position = element_to_find->new_position;
		while (element_to_find->new_position != i + median_src / j)
			element_to_find = element_to_find->next;
		if (index_1 > index_2)
			element_to_find->next_position = i;
		else
			element_to_find->next_position = element_to_find->new_position;
		i++;			
//	}
}

void	sort_step_ba_1(t_list **dest, int j, int i)
{
	int	size_dest;
	int	median_dest;
//	int	i;
	t_element	*element_to_find;
	int index_1;
	int index_2;

	size_dest = ft_lst_dc_size((*dest)->head);
	median_dest = size_dest / 2;
//	i = size_dest;
	index_1 = 1;
	index_2 = 1;
//	while (i > (j + 1) * median_dest / j)
//	{
		index_1 = search_index_element_with_new_position((*dest), i);
		ft_printf("index_1 : %d\n", index_1);
		index_2 = search_index_element_with_new_position((*dest), i - median_dest / j);
		ft_printf("index_2 : %d\n", index_2);
		element_to_find = (*dest)->head; 
		while (element_to_find->new_position != i)
			element_to_find = element_to_find->next;
		if (index_1 > index_2)
			element_to_find->next_position = i - median_dest / j;
		else
			element_to_find->next_position = element_to_find->new_position;
		while (element_to_find->new_position != i - median_dest / j)
			element_to_find = element_to_find->next;
		if (index_1 > index_2)
			element_to_find->next_position = i;
		else
			element_to_find->next_position = element_to_find->new_position;
		ft_printf("i ba_1 : %d\n", i);
		ft_printf("median : %d\n", median_dest);
//		i--;			
//	}
}

void	sort_step_ba_2(t_list **dest, int j, int i)
{
	int	size_dest;
	int	median_dest;
//	int	i;
	t_element	*element_to_find;
	int index_1;
	int index_2;

	size_dest = ft_lst_dc_size((*dest)->head);
	median_dest = size_dest / 2;
//	i = median_dest;
	index_1 = 1;
	index_2 = 1;
//	while ((i - (median_dest / j)) > 0)
//	{
		index_1 = search_index_element_with_new_position((*dest), i);
		ft_printf("index_1 : %d\n", index_1);
		index_2 = search_index_element_with_new_position((*dest), i - median_dest / j);
		ft_printf("index_2 : %d\n", index_2);
		element_to_find = (*dest)->head; 
		while (element_to_find->new_position != i)
			element_to_find = element_to_find->next;
		if (index_1 > index_2)
			element_to_find->next_position = i - median_dest / j;
		else
			element_to_find->next_position = element_to_find->new_position;
		while (element_to_find->new_position != i - median_dest / j)
			element_to_find = element_to_find->next;
		if (index_1 > index_2)
			element_to_find->next_position = i;
		else
			element_to_find->next_position = element_to_find->new_position;
		ft_printf("i ba_2 : %d\n", i);
		ft_printf("median : %d\n", median_dest);
//		i--;			
//	}
}

int	ft_butterfly(t_list	**src, t_list **dest, int chunk)
{
	int	size_src;
	int	chunk_len;
	int range;
	int	min_median;
	int	i;
	int hits = 0;// to delete

	size_src = ft_lst_dc_size((*src)->head);
	chunk_len = size_src / chunk;
	range = chunk_len;
	min_median = size_src / (chunk * 2);
	i = 1;

	while (ft_lst_dc_size((*src)->head))
	{
		if (optimizing_first_push(src, range) == 1)
			hits += ft_rotate_butterfly(src, dest, min_median, range, i);
		else if (optimizing_first_push(src, range) == 2)
			hits += ft_reverse_rotate_butterfly(src, dest, min_median, range, i);
		i += chunk_len;
		range += chunk_len;
	}
	return (hits);
}

int	ft_rotate_butterfly(t_list	**src, t_list **dest, int min_median, int range, int i)
{
	int hits = 0;// to delete

	while (i <= range && ft_lst_dc_size((*src)->head))
	{
		if ((*src)->head->index <= range)
		{
			push(&(*src)->head, &(*dest)->head, 'b');
			hits += 1;//to delete
			if ((*dest)->head->index > range - min_median)
			{
				rotate(&(*dest)->head, 'b');
				hits += 1;//to delete
			}
			i++;
//			ft_printf("i : %d\n", i);
		}
		else
		{
			rotate(&(*src)->head, 'a');
			hits += 1;//to delete
		}
	}
	return (hits);
}

int	ft_reverse_rotate_butterfly(t_list	**src, t_list **dest, int min_median, int range, int i)
{
	int hits = 0;// to delete

	while (i <= range && ft_lst_dc_size((*src)->head))
	{
		if ((*src)->head->index <= range)
		{
			push(&(*src)->head, &(*dest)->head, 'b');
			hits += 1;//to delete
			if ((*dest)->head->index > range - min_median)
			{
				reverse_rotate(&(*dest)->head, 'b');
				hits += 1;//to delete
			}
			i++;
//			ft_printf("i : %d\n", i);
		}
		else
		{
			reverse_rotate(&(*src)->head, 'a');
			hits += 1;//to delete
		}
	}
	return (hits);
}

int	ft_sort_back(t_list **src, t_list **dest)
{
	int	size_dest;
	int	i;
	int hits = 0;//to delete
	int	j;
	int k;

	size_dest = ft_lst_dc_size((*dest)->head);
	while (ft_lst_dc_size((*dest)->head))
	{
		i = ft_lst_dc_size((*dest)->head);
		if (i > 1)
			j = i - 1;
		k = optimizing_last_push(dest, i, j);
		if (k == 1)
		{
			hits += search_best_sort_index(dest, src, j);
			hits += search_best_sort_index(dest, src, i);
			swap(&(*src)->head, 'a');
			hits += 1;
		}
		else
			hits += search_best_sort_index(dest, src, i);
	}
	return (hits);
}

int	optimizing_last_push(t_list **dest, int index_1, int index_2)
{
	int	median_dest;
	int new_position_1;
	int new_position_2;

	median_dest = ft_lst_dc_size((*dest)->head) / 2;
	new_position_1 = search_new_position_element_with_index((*dest), index_1);
	ft_printf("index_1 : %d\n", index_1);// to delete
	new_position_2 = search_new_position_element_with_index((*dest), index_2);
	ft_printf("index_2 : %d\n", index_2);//to delete
	if (new_position_1 == 0 || new_position_2 == 0)
	{
		/*free_tab(str_arr);
		free(int_arr);
		free_linked_list(&stack_a);
		free_linked_list(&stack_b);*/
		ft_putstr_fd("Error\nAt least one searched element " \
			"wasn't found in optimizing_push function\n", 2);
		exit(EXIT_FAILURE);
	}
	if (new_position_1 <= median_dest && new_position_2 <= median_dest &&
		new_position_2 < new_position_1)
			return (1);
	if (new_position_1 > median_dest && new_position_2 > median_dest &&
		new_position_2 > new_position_1)
			return (1);
	else
		return (0);		
}

int	optimizing_first_push(t_list **src, int range)
{
	int	count_rotate;
	int	count_reverse_rotate;
	t_element	*tmp;
	int	i;

	count_rotate = 1;
	count_reverse_rotate = 1;
	i = 0;
	tmp = (*src)->head;
	while (i != (int)ft_lst_dc_size((*src)->head))
	{
		if (tmp->index <= range)
			count_rotate += search_new_position_element_with_index(*src, tmp->index);
		tmp = tmp->next;
		i++;
	}
	tmp = (*src)->head;
	i = (int)ft_lst_dc_size((*src)->head);
	while (i > 0)
	{
		if (tmp->index <= range)
			count_reverse_rotate += search_new_position_element_with_index(*src, tmp->index);
		tmp = tmp->previous;
		i--;
	}
	ft_printf("count_rotate : %d\n", count_rotate);
	ft_printf("count_reverse_rotate : %d\n", count_reverse_rotate);
	if (count_rotate >= count_reverse_rotate)
		return (1);
	else
		return (2);
}

