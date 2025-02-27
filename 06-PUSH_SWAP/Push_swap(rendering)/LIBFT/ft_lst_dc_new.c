/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_dc_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:39:07 by ppuivif           #+#    #+#             */
/*   Updated: 2024/03/27 13:42:24 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_element	*ft_lst_dc_new(int content, int index, int initial_position)
{
	t_element	*new_element;

	new_element = malloc(sizeof(t_element));
	if (!new_element)
		return (NULL);
	else
	{
		new_element->number = content;
		new_element->index = index;
		new_element->initial_position = initial_position;
		new_element->new_position = 1;
		new_element->next_position = 1;
		new_element->next = NULL;
		new_element->previous = NULL;
	}
	return (new_element);
}
