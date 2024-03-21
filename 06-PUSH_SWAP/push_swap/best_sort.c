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

/*int	search_best_sort_index(t_list **src, t_list **dest, int index)//int to modify in void
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
}*/

int	search_best_sort_index(t_list **src, t_list **dest, char s, char d, int index)//int to modify in void
{
	int	size_src;
	int	hits;//to delete

	size_src = ft_lst_dc_size((*src)->head);
	hits = 0;//to delete
	if (search_new_position_element_with_index((*src), index) <= size_src / 2)
	{
		while ((*src)->head->index != index)
		{
			rotate(&(*src)->head, s);
			update_new_position(&(*src)->head);
			hits++;//to delete
		}
		push(&(*src)->head, &(*dest)->head, d);
		update_new_position(&(*src)->head);
		hits++;//to delete
	}
	else
	{
		while ((*src)->head->index != index)
		{
			reverse_rotate(&(*src)->head, s);
			update_new_position(&(*src)->head);
			hits++;//to delete
		}
		push(&(*src)->head, &(*dest)->head, d);
		update_new_position(&(*src)->head);
		hits++;//to delete
	}
	return (hits);//to delete
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
			}
			else
			{
				rotate(&(*src)->head, 'a');
				hits += 1;//to delete
			}
		}
		range += chunk_len;
	}
	return (hits);
}

int	ft_sort_back(t_list **src, t_list **dest)
{
	int	size_dest;
	int	i;
	int hits = 0;//to delete
//	int	j;

	size_dest = ft_lst_dc_size((*dest)->head);
	while (ft_lst_dc_size((*dest)->head))
	{
		i = ft_lst_dc_size((*dest)->head);
//		ft_printf("i : %d\n", i);
		if (i > 1 && optimizing_last_push(dest, i, i - 1) == 1)
		{
	//		ft_printf("i : %d\n", i);
	//		ft_printf("i - 1 : %d\n", i-1);
			hits += search_best_sort_index(dest, src, 'b', 'a', i - 1);
			hits += search_best_sort_index(dest, src, 'b', 'a', i);
			swap(&(*src)->head, 'a');
			hits += 1;
		}
		else
			hits += search_best_sort_index(dest, src, 'b', 'a', i);
	}
	return (hits);
}

int	optimizing_last_push(t_list **dest, int index_max, int index_max_minus_1)
{
	int	median_dest;
	int new_position_1;
	int new_position_2;

	median_dest = ft_lst_dc_size((*dest)->head) / 2;
	new_position_1 = search_new_position_element_with_index((*dest), index_max);
	new_position_2 = search_new_position_element_with_index((*dest), index_max_minus_1);
//	ft_printf("index_1 %d\n", index_max);
//	ft_printf("index_2 %d\n", index_max_minus_1);
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


