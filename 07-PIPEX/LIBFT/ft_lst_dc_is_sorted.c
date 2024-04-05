/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_dc_is_sorted.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:38:59 by ppuivif           #+#    #+#             */
/*   Updated: 2024/03/30 14:34:26 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_dc_is_sorted(t_element *head)
{
	size_t	len;

	len = ft_lst_dc_size(head);
	if (len == 0)
		return (1);
	if (len == 1)
		return (0);
	while (len > 1)
	{
		if (head->number < head->next->number)
			head = head->next;
		else
			return (1);
		len--;
	}
	return (0);
}
