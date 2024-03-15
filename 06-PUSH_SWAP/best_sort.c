#include "push_swap.h"

int	search_position(t_list	*list, int index)
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

int	search_best_sort(t_list **src, t_list **dest, int index)
{
	int	size_src;
	int	hits;

	size_src = ft_lst_dc_size((*src)->head);
	hits = 0;
	if (search_position((*src), index) <= size_src / 2)
	{
		while ((*src)->head->index != index)
		{
			rotate(&(*src)->head, 'a');
			hits++;
		}
		push(&(*src)->head, &(*dest)->head, 'b');
		hits++;
	}
	else
	{
		while ((*src)->head->index != index)
		{
			reverse_rotate(&(*src)->head, 'a');
			hits++;
		}
		push(&(*src)->head, &(*dest)->head, 'b');
		hits++;
	}
	return (hits);
}

void	ft_sort_2a(t_list **src, t_list **dest)
{
		push(&(*src)->head, &(*dest)->head, 'b');
		push(&(*src)->head, &(*dest)->head, 'b');
}

void	ft_sort_2b(t_list **src, t_list **dest)
{
		push(&(*src)->head, &(*dest)->head, 'b');
		push(&(*src)->head, &(*dest)->head, 'b');
		swap(&(*dest)->head, 'b');
}

/*void	ft_sort_2b(t_list **src, t_list **dest)
{
		while ((*src)->head->index != 1)
			rotate(&(*src)->head, 'a');
		push(&(*src)->head, &(*dest)->head, 'b');
		while ((*src)->head->index != 2)
			rotate(&(*src)->head, 'a');
		push(&(*src)->head, &(*dest)->head, 'b');
}*/
