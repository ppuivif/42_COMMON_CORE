/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_linked_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:41:16 by ppuivif           #+#    #+#             */
/*   Updated: 2024/03/27 11:44:46 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_linked_list(t_list **list)
{
	int	size;

	size = ft_lst_dc_size((*list)->head);
	while (size > 1)
	{
		ft_lst_dc_delone(&(*list)->head, (*list)->head);
		size--;
	}
	free((*list)->head);
	free(*list);
}
