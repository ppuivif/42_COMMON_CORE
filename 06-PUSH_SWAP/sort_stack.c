#include "push_swap.h"

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
	ft_printf("%d\n", combination((*src), 1, 2));

	if (combination((*src), 1, 2) == 5)
		ft_sort_2a(src, dest);
	if (combination((*src), 1, 2) == 4)
		ft_sort_2b(src, dest);
	/*	{
		search_best_sort(src, dest, 1);
	}*/
	if (ft_lst_dc_size((*src)->head) == 2)
		ft_sort_2(src);
	else
		ft_sort_3(src, dest);
	push(&(*dest)->head, &(*src)->head, 'a');
	push(&(*dest)->head, &(*src)->head, 'a');
}




	
/*		//ft_printf("index 1 at position 1 in src\n");
	if (search_index((*dest), 1) == 1)
		ft_printf("index 1 at position 1 in dest\n");






	int		result_src;
	int		result_dest;

	
	
	if (result_src < (2 * 15 / 3))
	
	push_index_1(*src);
	push_index_2(*src);

	if (result_src < (2 * 15 / 3))


	result_src = search_best_sort(*src);
	ft_printf("result : %d\n", result_src);

	result_dest = search_best_sort(*dest);
	ft_printf("result : %d\n", result_dest);

	ft_printf("max_src : %d\n", search_max(*src));
	ft_printf("max_src til median : %d\n", search_max_til_median(*src));
	ft_printf("max_dest : %d\n", search_max(*dest));
}*/


