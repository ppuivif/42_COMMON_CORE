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
	update_new_position(&(*src)->head);//to delete
}

void	ft_sort_5(t_list **src, t_list **dest)
{
	//ft_printf("%d\n", combination((*src), 1, 2));

/*	if (combination((*src), 1, 2) == 4)//not sorted
	{
		if (combination((*src), 3, 5) == 50)//sorted
			swap(&(*src)->head, 'a');
		else
		{
			ft_sort_2b(src, dest);
			ft_sort_3(src, dest);
			push(&(*dest)->head, &(*src)->head, 'a');
			push(&(*dest)->head, &(*src)->head, 'a');
		}
	}
	else if (combination((*src), 1, 2) == 5)//sorted
	{
		ft_sort_2a(src, dest);
		ft_sort_3(src, dest);
		push(&(*dest)->head, &(*src)->head, 'a');
		push(&(*dest)->head, &(*src)->head, 'a');
	}
	else if (combination((*src), 1, 2) == 13)//not sorted
	{
		reverse_rotate(&(*src)->head, 'a');
		reverse_rotate(&(*src)->head, 'a');
		if (combination((*src), 3, 5) == 50)//sorted
			swap(&(*src)->head, 'a');
		else
		{
			ft_sort_2b(src, dest);
			ft_sort_3(src, dest);
			push(&(*dest)->head, &(*src)->head, 'a');
			push(&(*dest)->head, &(*src)->head, 'a');
		}
	}
	else if (combination((*src), 1, 2) == 14)//sorted
	{
		reverse_rotate(&(*src)->head, 'a');
		reverse_rotate(&(*src)->head, 'a');
		ft_sort_2a(src, dest);
		ft_sort_3(src, dest);
		push(&(*dest)->head, &(*src)->head, 'a');
		push(&(*dest)->head, &(*src)->head, 'a');
	}
	else*/
		search_best_sort_index(src, dest, 1);
		search_best_sort_index(src, dest, 2);
	if (ft_lst_dc_size((*src)->head) == 2)
		ft_sort_2(src);
	else
		ft_sort_3(src, dest);
	push(&(*dest)->head, &(*src)->head, 'a');
	push(&(*dest)->head, &(*src)->head, 'a');
	update_new_position(&(*src)->head);//to delete
 	}

/*void	ft_sort_50(t_list **src, t_list **dest)
{
//	int	median_src;
//	int	median_dest;
	int hits;//to delete
	int j;


	//median_src = ft_lst_dc_size((*src)->head) / 2 + 1;

	hits = 0;//to delete
	j = 1;
//	while (median_src / j > 0)
//	{
		hits += ft_butterfly_ab(src, dest, j);
		j*=2;
		ft_printf("j : %d\n", j);
	ft_lst_dc_print((*src)->head);
	ft_lst_dc_print((*dest)->head);
		hits += ft_butterfly_ba(src, dest, j);
		hits += ft_butterfly_ba(src, dest, j);
//		j*=2;
//		ft_printf("j : %d\n", j);
//	}
		ft_printf("hits : %d\n", hits);//to delete
	ft_putstr_fd("\nstack_a after sort :\n" ,1);
	ft_lst_dc_print((*src)->head);
	ft_putstr_fd("\nstack_b after sort :\n" ,1);
	ft_lst_dc_print((*dest)->head);
}*/

void	ft_sort_50(t_list **src, t_list **dest)
{
//	int	median_src;
	int size_src;
//	int	median_dest;
	int hits;//to delete
	int i;
	int j;


	size_src = ft_lst_dc_size((*src)->head);
	//median_src = size_src / 2 + 1;

	hits = 0;//to delete
	i = 1;
	j = 1;
	sort_step_1(src, j);

	while (i <= size_src)
	{
		hits += search_best_sort_next_position(src, dest, i);
		i++;
	}
//	ft_lst_dc_print((*dest)->head);
	update_new_position(&(*dest)->head);	
	ft_lst_dc_print((*dest)->head);




}








void	ft_sort_100(t_list **src, t_list **dest)
{
	int	i;
	int j;
	int size_src;
	int size_dest;
	int hits;//to delete
	
	i = 1;
	size_src = ft_lst_dc_size((*src)->head);
	hits = 0;//to delete
	while (i <= size_src / 4)
	{
		hits += search_best_sort_index(src, dest, i);
		i++;
	}

	while (i <= size_src / 2)
	{
		hits += search_best_sort_index(src, dest, i);
		i++;
	}
	
	while (i <= (3 * size_src / 4))
	{
		hits += search_best_sort_index(src, dest, i);
		i++;
	}

	while (i <= size_src)
	{
		hits += search_best_sort_index(src, dest, i);
		i++;
	}

	size_dest = ft_lst_dc_size((*dest)->head);
	j = size_dest;
	while (j > (3 * size_dest / 4))
	{
		hits += search_best_sort_index(dest, src, j);
		j--;
	}
	while (j > size_dest / 2)
	{
		hits += search_best_sort_index(dest, src, j);
		j--;
	}
	while (j > size_dest / 4)
	{
		hits += search_best_sort_index(dest, src, j);
		j--;
	}
	while (j > 0)
	{
		hits += search_best_sort_index(dest, src, j);
		j--;
	}
	ft_printf("hits : %d\n", hits);//to delete
}

/*void	ft_sort_100(t_list **src, t_list **dest)//same result as previous
{
	int	i;
	int j;
	int size_src;
	int size_dest;
	int hits;//to delete
	
	i = 1;
	size_src = ft_lst_dc_size((*src)->head);
	hits = 0;//to delete
	while (i <= size_src)
	{
		hits += search_best_sort(src, dest, i);
		i++;
	}
	size_dest = ft_lst_dc_size((*dest)->head);
	j = size_dest;
	while (j > 0)
	{
		hits += search_best_sort(dest, src, j);
		j--;
	}
	ft_printf("hits : %d\n", hits);
}*/


	
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


