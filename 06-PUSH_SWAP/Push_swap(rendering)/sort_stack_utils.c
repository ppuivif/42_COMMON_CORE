/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:02:23 by ppuivif           #+#    #+#             */
/*   Updated: 2024/03/30 13:24:57 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			return (tmp_element->new_position);
		tmp_element = tmp_element->next;
		i++;
	}
	return (0);
}

void	search_best_sort_index(t_list **src, t_list **dest,
		char *char_to_print, int index)
{
	int	size_src;

	size_src = ft_lst_dc_size((*src)->head);
	if (search_new_position_element_with_index((*src), index) <= size_src / 2)
	{
		while ((*src)->head->index != index)
		{
			rotate(&(*src)->head, char_to_print[0]);
			update_new_position(&(*src)->head);
		}
		push(&(*src)->head, &(*dest)->head, char_to_print[1]);
		update_new_position(&(*src)->head);
	}
	else
	{
		while ((*src)->head->index != index)
		{
			reverse_rotate(&(*src)->head, char_to_print[0]);
			update_new_position(&(*src)->head);
		}
		push(&(*src)->head, &(*dest)->head, char_to_print[1]);
		update_new_position(&(*src)->head);
	}
}

void	ft_butterfly(t_list	**src, t_list **dest, int chunk)
{
	int	chunk_len;
	int	range;
	int	min_median;
	int	i;

	chunk_len = ft_lst_dc_size((*src)->head) / chunk;
	range = chunk_len;
	min_median = ft_lst_dc_size((*src)->head) / (chunk * 2);
	i = 1;
	while (ft_lst_dc_size((*src)->head))
	{
		while (i <= range && ft_lst_dc_size((*src)->head))
		{
			if ((*src)->head->index <= range)
			{
				push(&(*src)->head, &(*dest)->head, 'b');
				if ((*dest)->head->index > range - min_median)
					rotate(&(*dest)->head, 'b');
				i++;
			}
			else
				rotate(&(*src)->head, 'a');
		}
		range += chunk_len;
	}
}

void	ft_sort_back(t_list **src, t_list **dest)
{
	int		size_dest;
	int		i;
	char	*char_to_print;

	char_to_print = "ba";
	size_dest = ft_lst_dc_size((*dest)->head);
	while (ft_lst_dc_size((*dest)->head))
	{
		i = ft_lst_dc_size((*dest)->head);
		if (i > 1 && optimizing_last_push(dest, i, i - 1) == 0)
		{
			search_best_sort_index(dest, src, char_to_print, i - 1);
			search_best_sort_index(dest, src, char_to_print, i);
			swap(&(*src)->head, 'a');
		}
		else
			search_best_sort_index(dest, src, char_to_print, i);
	}
}

int	optimizing_last_push(t_list **dest, int index_max, int index_max_minus_1)
{
	int	median_dest;
	int	new_position_1;
	int	new_position_2;

	median_dest = ft_lst_dc_size((*dest)->head) / 2;
	new_position_1 = search_new_position_element_with_index((*dest), index_max);
	new_position_2 = search_new_position_element_with_index((*dest),
			index_max_minus_1);
	if (new_position_1 <= median_dest && new_position_2 <= median_dest \
	&& new_position_2 < new_position_1)
		return (0);
	if (new_position_1 > median_dest && new_position_2 > median_dest \
	&& new_position_2 > new_position_1)
		return (0);
	else
		return (1);
}
