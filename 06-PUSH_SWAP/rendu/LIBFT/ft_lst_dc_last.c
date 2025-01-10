/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_dc_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:24:06 by ppuivif           #+#    #+#             */
/*   Updated: 2024/03/27 13:43:45 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_element	*ft_lst_dc_last(t_element *head)
{
	t_element	*last_element;

	if (!head)
		return (NULL);
	if (!head->previous)
		last_element = head;
	else
		last_element = head->previous;
	return (last_element);
}
