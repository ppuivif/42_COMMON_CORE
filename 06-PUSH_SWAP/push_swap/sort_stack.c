#include "push_swap.h"

void	sort_stack_a(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->size == 2)
		ft_sort_2(stack_a);
	else if ((*stack_a)->size <= 3)
		ft_sort_3(stack_a, stack_b);
	else if ((*stack_a)->size <= 5)
		ft_sort_5(stack_a, stack_b);
	else if ((*stack_a)->size <= 100)
		ft_sort_500(stack_a, stack_b, 3);
	else if ((*stack_a)->size <= 200)
		ft_sort_500(stack_a, stack_b, 4);
	else if ((*stack_a)->size <= 300)
		ft_sort_500(stack_a, stack_b, 5);
	else if ((*stack_a)->size <= 400)
		ft_sort_500(stack_a, stack_b, 6);
	else if ((*stack_a)->size > 400)
		ft_sort_500(stack_a, stack_b, 8);
}

void	ft_sort_2(t_list **src)
{
	swap(&(*src)->head, 'a');
}

void	ft_sort_3(t_list **src, t_list **dest)
{
	if ((*src)->head->number < (*src)->head->next->number &&
		(*src)->head->number < (*src)->head->previous->number)
	{
		push(&(*src)->head, &(*dest)->head, 'b');
		rotate(&(*src)->head, 'a');
		push(&(*dest)->head, &(*src)->head, 'a');
	}
	else if ((*src)->head->next->number < (*src)->head->number &&
		(*src)->head->next->number < (*src)->head->previous->number)
	{
		if ((*src)->head->number < (*src)->head->previous->number)
			swap(&(*src)->head, 'a');
		else
			rotate(&(*src)->head, 'a');	
	}
	else
	{
		if ((*src)->head->next->number < (*src)->head->number)
		{
			swap(&(*src)->head, 'a');
		}
		reverse_rotate(&(*src)->head, 'a');	
	}
}

void	ft_sort_5(t_list **src, t_list **dest)
{
	search_best_sort_index(src, dest, 'a', 'b', 1);
	search_best_sort_index(src, dest, 'a', 'b', 2);
	if (ft_lst_dc_size((*src)->head) == 2 && ft_lst_dc_is_sorted((*src)->head) == 0)
		ft_sort_2(src);
	else if (ft_lst_dc_size((*src)->head) == 3 && ft_lst_dc_is_sorted((*src)->head) == 0)
		ft_sort_3(src, dest);
	push(&(*dest)->head, &(*src)->head, 'a');
	push(&(*dest)->head, &(*src)->head, 'a');
 	}


void	ft_sort_500(t_list **src, t_list **dest, int chunk)
{
	int hits = 0;// to delete

	hits += ft_butterfly(src, dest, chunk);//to modify
	update_new_position(&(*dest)->head);//to delete
	hits += ft_sort_back(src, dest);//to modify
//	ft_lst_dc_print((*dest)->head);//to delete*/
}
