/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_dc_delone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:29:05 by ppuivif           #+#    #+#             */
/*   Updated: 2024/04/01 19:31:47 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_dc_delone_util(t_element **head, t_element *element_to_del)
{
	int	size;

	size = ft_lst_dc_size(*head);
	if (size == 1)
	{
		*head = NULL;
		free(element_to_del);
		return (1);
	}
	else if (size == 2)
	{
		*head = (*head)->next ;
		(*head)->next = NULL;
		(*head)->previous = NULL;
		free(element_to_del);
		return (1);
	}
	*head = element_to_del->next;
	return (0);
}

void	ft_lst_dc_delone(t_element **head, t_element *element_to_del)
{
	t_element	*element_to_search;
	int			size;

	size = ft_lst_dc_size(*head);
	if (!element_to_del || !head)
		return ;
	if (*head == element_to_del)
	{
		if (ft_lst_dc_delone_util(head, element_to_del) == 1)
			return ;
	}
	element_to_search = *head;
	while (element_to_search->next != element_to_del)
		element_to_search = element_to_search->next;
	element_to_search->next = element_to_search->next->next;
	element_to_search->next->previous = element_to_search;
	free(element_to_del);
}
