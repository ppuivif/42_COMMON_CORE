/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_dc_add_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:38:53 by ppuivif           #+#    #+#             */
/*   Updated: 2024/03/27 13:44:16 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_dc_add_front(t_element **head, t_element *new_element)
{
	t_element	*last_element;

	if (!new_element || !head)
		return ;
	if (!*head)
		*head = new_element;
	else
	{
		last_element = ft_lst_dc_last(*head);
		new_element->next = *head;
		new_element->previous = last_element;
		last_element->next = new_element;
		(*head)->previous = new_element;
		*head = new_element;
	}
}
